using ClientesApi.Models;
using Microsoft.EntityFrameworkCore;

namespace ClientesApi.Data;

/// <summary>
/// Contexto de Entity Framework Core que representa la sesión con la base de datos.
/// </summary>
public class AppDbContext(DbContextOptions<AppDbContext> options) : DbContext(options)
{
    public DbSet<Cliente> Clientes => Set<Cliente>();

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        modelBuilder.Entity<Cliente>(entity =>
        {
            entity.HasKey(c => c.Id_cliente);

            // El CUI (DPI) es único por persona.
            entity.HasIndex(c => c.CUI)
                  .IsUnique()
                  .HasDatabaseName("UX_Clientes_CUI");

            entity.Property(c => c.CUI).HasMaxLength(13).IsUnicode(false);
            entity.Property(c => c.NIT).HasMaxLength(15).IsUnicode(false);
            entity.Property(c => c.Nombres).HasMaxLength(100);
            entity.Property(c => c.Apellidos).HasMaxLength(100);
            entity.Property(c => c.Direccion).HasMaxLength(200);
            entity.Property(c => c.Telefono).HasMaxLength(20).IsUnicode(false);
            entity.Property(c => c.Fecha_Nacimiento).HasColumnType("date");
        });
    }
}
