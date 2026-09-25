using ClientesApi.Data;
using Microsoft.EntityFrameworkCore;

var builder = WebApplication.CreateBuilder(args);

// ---------------------------------------------------------------
// 1. Servicios
// ---------------------------------------------------------------

// Cadena de conexión definida en appsettings.json -> ConnectionStrings:ClientesDB
var connectionString = builder.Configuration.GetConnectionString("ClientesDB")
    ?? throw new InvalidOperationException("No se encontró la cadena de conexión 'ClientesDB' en appsettings.json.");

// Entity Framework Core con SQL Server
builder.Services.AddDbContext<AppDbContext>(options =>
    options.UseSqlServer(connectionString));

builder.Services
    .AddControllers()
    .AddJsonOptions(options =>
    {
        // Mantiene los nombres de las propiedades tal como están en el modelo
        // (Id_cliente, CUI, NIT, Fecha_Nacimiento, ...).
        options.JsonSerializerOptions.PropertyNamingPolicy = null;
    });

// Documento OpenAPI (/openapi/v1.json)
builder.Services.AddOpenApi();

var app = builder.Build();

// ---------------------------------------------------------------
// 2. Crear la base de datos y la tabla si no existen
// ---------------------------------------------------------------
using (var scope = app.Services.CreateScope())
{
    var db = scope.ServiceProvider.GetRequiredService<AppDbContext>();
    var logger = scope.ServiceProvider.GetRequiredService<ILogger<Program>>();

    try
    {
        db.Database.EnsureCreated();
        logger.LogInformation("Base de datos lista.");
    }
    catch (Exception ex)
    {
        logger.LogError(ex,
            "No se pudo conectar a SQL Server. Revisa la cadena de conexión 'ClientesDB' en appsettings.json " +
            "y que el servicio de SQL Server esté iniciado.");
    }
}

// ---------------------------------------------------------------
// 3. Pipeline HTTP
// ---------------------------------------------------------------
app.MapOpenApi();

// Interfaz de Swagger para probar la API desde el navegador: /swagger
app.UseSwaggerUI(options =>
{
    options.SwaggerEndpoint("/openapi/v1.json", "Clientes API v1");
    options.DocumentTitle = "Clientes API";
});

// La raíz redirige a Swagger
app.MapGet("/", () => Results.Redirect("/swagger")).ExcludeFromDescription();

app.UseHttpsRedirection();

app.UseAuthorization();

app.MapControllers();

app.Run();
