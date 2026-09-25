using ClientesApi.Data;
using ClientesApi.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace ClientesApi.Controllers;

/// <summary>
/// Controlador REST para la administración de clientes (CRUD).
/// Ruta base: /api/Clientes
/// </summary>
[ApiController]
[Route("api/[controller]")]
[Produces("application/json")]
public class ClientesController(AppDbContext context) : ControllerBase
{
    private readonly AppDbContext _context = context;

    // GET: api/Clientes
    /// <summary>Obtiene el listado completo de clientes.</summary>
    [HttpGet]
    [ProducesResponseType(StatusCodes.Status200OK)]
    public async Task<ActionResult<IEnumerable<Cliente>>> GetClientes()
    {
        var clientes = await _context.Clientes
            .AsNoTracking()
            .OrderBy(c => c.Id_cliente)
            .ToListAsync();

        return Ok(clientes);
    }

    // GET: api/Clientes/5
    /// <summary>Obtiene la información de un cliente específico por su Id.</summary>
    [HttpGet("{id:int}")]
    [ProducesResponseType(StatusCodes.Status200OK)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<ActionResult<Cliente>> GetCliente(int id)
    {
        var cliente = await _context.Clientes
            .AsNoTracking()
            .FirstOrDefaultAsync(c => c.Id_cliente == id);

        if (cliente is null)
        {
            return NotFound(new { mensaje = $"No existe un cliente con Id {id}." });
        }

        return Ok(cliente);
    }

    // POST: api/Clientes
    /// <summary>Registra un nuevo cliente en la base de datos.</summary>
    [HttpPost]
    [Consumes("application/json")]
    [ProducesResponseType(StatusCodes.Status201Created)]
    [ProducesResponseType(StatusCodes.Status400BadRequest)]
    [ProducesResponseType(StatusCodes.Status409Conflict)]
    public async Task<ActionResult<Cliente>> PostCliente(Cliente cliente)
    {
        Normalizar(cliente);
        cliente.Id_cliente = 0; // El Id lo genera la base de datos (IDENTITY).

        if (await _context.Clientes.AnyAsync(c => c.CUI == cliente.CUI))
        {
            return Conflict(new { mensaje = $"Ya existe un cliente registrado con el CUI {cliente.CUI}." });
        }

        _context.Clientes.Add(cliente);

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateException)
        {
            if (await _context.Clientes.AnyAsync(c => c.CUI == cliente.CUI))
            {
                return Conflict(new { mensaje = $"Ya existe un cliente registrado con el CUI {cliente.CUI}." });
            }
            throw;
        }

        return CreatedAtAction(nameof(GetCliente), new { id = cliente.Id_cliente }, cliente);
    }

    // PUT: api/Clientes/5
    /// <summary>Actualiza la información de un cliente existente.</summary>
    [HttpPut("{id:int}")]
    [Consumes("application/json")]
    [ProducesResponseType(StatusCodes.Status204NoContent)]
    [ProducesResponseType(StatusCodes.Status400BadRequest)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    [ProducesResponseType(StatusCodes.Status409Conflict)]
    public async Task<IActionResult> PutCliente(int id, Cliente cliente)
    {
        // Si el cuerpo no trae Id, se toma el de la ruta.
        if (cliente.Id_cliente == 0)
        {
            cliente.Id_cliente = id;
        }

        if (id != cliente.Id_cliente)
        {
            return BadRequest(new { mensaje = "El Id de la ruta no coincide con el Id_cliente del cuerpo de la solicitud." });
        }

        var existente = await _context.Clientes.FindAsync(id);
        if (existente is null)
        {
            return NotFound(new { mensaje = $"No existe un cliente con Id {id}." });
        }

        Normalizar(cliente);

        if (await _context.Clientes.AnyAsync(c => c.CUI == cliente.CUI && c.Id_cliente != id))
        {
            return Conflict(new { mensaje = $"El CUI {cliente.CUI} ya pertenece a otro cliente." });
        }

        existente.CUI = cliente.CUI;
        existente.NIT = cliente.NIT;
        existente.Nombres = cliente.Nombres;
        existente.Apellidos = cliente.Apellidos;
        existente.Direccion = cliente.Direccion;
        existente.Telefono = cliente.Telefono;
        existente.Fecha_Nacimiento = cliente.Fecha_Nacimiento;

        try
        {
            await _context.SaveChangesAsync();
        }
        catch (DbUpdateConcurrencyException)
        {
            if (!await _context.Clientes.AnyAsync(c => c.Id_cliente == id))
            {
                return NotFound(new { mensaje = $"No existe un cliente con Id {id}." });
            }
            throw;
        }
        catch (DbUpdateException)
        {
            if (await _context.Clientes.AnyAsync(c => c.CUI == cliente.CUI && c.Id_cliente != id))
            {
                return Conflict(new { mensaje = $"El CUI {cliente.CUI} ya pertenece a otro cliente." });
            }
            throw;
        }

        return NoContent();
    }

    // DELETE: api/Clientes/5
    /// <summary>Elimina un cliente de la base de datos.</summary>
    [HttpDelete("{id:int}")]
    [ProducesResponseType(StatusCodes.Status204NoContent)]
    [ProducesResponseType(StatusCodes.Status404NotFound)]
    public async Task<IActionResult> DeleteCliente(int id)
    {
        var cliente = await _context.Clientes.FindAsync(id);
        if (cliente is null)
        {
            return NotFound(new { mensaje = $"No existe un cliente con Id {id}." });
        }

        _context.Clientes.Remove(cliente);
        await _context.SaveChangesAsync();

        return NoContent();
    }

    /// <summary>Limpia espacios y unifica el formato de los datos recibidos.</summary>
    private static void Normalizar(Cliente cliente)
    {
        cliente.CUI = cliente.CUI.Trim();
        cliente.NIT = cliente.NIT.Trim().ToUpperInvariant();
        cliente.Nombres = cliente.Nombres.Trim();
        cliente.Apellidos = cliente.Apellidos.Trim();
        cliente.Direccion = cliente.Direccion.Trim();
        cliente.Telefono = cliente.Telefono.Trim();
    }
}
