using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace ClientesApi.Models;

/// <summary>
/// Entidad que representa a un cliente en la base de datos.
/// </summary>
[Table("Clientes")]
public class Cliente : IValidatableObject
{
    [Key]
    [DatabaseGenerated(DatabaseGeneratedOption.Identity)]
    public int Id_cliente { get; set; }

    /// <summary>Código Único de Identificación (DPI): 13 dígitos.</summary>
    [Required(ErrorMessage = "El CUI es obligatorio.")]
    [MaxLength(13)]
    [RegularExpression(@"^\d{13}$", ErrorMessage = "El CUI debe tener exactamente 13 dígitos numéricos.")]
    public string CUI { get; set; } = string.Empty;

    /// <summary>Número de Identificación Tributaria. Ej.: 1234567-8, 12345678K o CF.</summary>
    [Required(ErrorMessage = "El NIT es obligatorio.")]
    [StringLength(15, ErrorMessage = "El NIT no puede exceder 15 caracteres.")]
    [RegularExpression(@"^(\d{1,13}-?[\dKk]|CF|cf)$", ErrorMessage = "El NIT no tiene un formato válido (ej.: 1234567-8, 12345678K o CF).")]
    public string NIT { get; set; } = string.Empty;

    [Required(ErrorMessage = "Los nombres son obligatorios.")]
    [StringLength(100, ErrorMessage = "Los nombres no pueden exceder 100 caracteres.")]
    public string Nombres { get; set; } = string.Empty;

    [Required(ErrorMessage = "Los apellidos son obligatorios.")]
    [StringLength(100, ErrorMessage = "Los apellidos no pueden exceder 100 caracteres.")]
    public string Apellidos { get; set; } = string.Empty;

    [Required(ErrorMessage = "La dirección es obligatoria.")]
    [StringLength(200, ErrorMessage = "La dirección no puede exceder 200 caracteres.")]
    public string Direccion { get; set; } = string.Empty;

    /// <summary>Teléfono de 8 dígitos. Ej.: 55551234, 5555-1234 o +502 55551234.</summary>
    [Required(ErrorMessage = "El teléfono es obligatorio.")]
    [StringLength(20, ErrorMessage = "El teléfono no puede exceder 20 caracteres.")]
    [RegularExpression(@"^(\+502\s?)?\d{4}-?\d{4}$", ErrorMessage = "El teléfono debe tener 8 dígitos (ej.: 55551234, 5555-1234 o +502 55551234).")]
    public string Telefono { get; set; } = string.Empty;

    /// <summary>Fecha de nacimiento en formato yyyy-MM-dd.</summary>
    [Required(ErrorMessage = "La fecha de nacimiento es obligatoria.")]
    [Column(TypeName = "date")]
    public DateOnly Fecha_Nacimiento { get; set; }

    public IEnumerable<ValidationResult> Validate(ValidationContext validationContext)
    {
        var hoy = DateOnly.FromDateTime(DateTime.Today);

        if (Fecha_Nacimiento < new DateOnly(1900, 1, 1) || Fecha_Nacimiento > hoy)
        {
            yield return new ValidationResult(
                "La fecha de nacimiento debe estar entre 1900-01-01 y la fecha actual.",
                [nameof(Fecha_Nacimiento)]);
        }
    }
}
