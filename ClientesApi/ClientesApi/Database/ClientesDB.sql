/* =====================================================================
   Script de base de datos - API de Clientes
   OPCIONAL: la API crea la base de datos y la tabla automáticamente
   al iniciar (Database.EnsureCreated). Usa este script solo si prefieres
   crearla a mano desde SQL Server Management Studio.
   ===================================================================== */

IF DB_ID(N'ClientesDB') IS NULL
    CREATE DATABASE ClientesDB;
GO

USE ClientesDB;
GO

IF OBJECT_ID(N'dbo.Clientes', N'U') IS NULL
BEGIN
    CREATE TABLE dbo.Clientes
    (
        Id_cliente       INT            IDENTITY(1,1) NOT NULL,
        CUI              VARCHAR(13)    NOT NULL,
        NIT              VARCHAR(15)    NOT NULL,
        Nombres          NVARCHAR(100)  NOT NULL,
        Apellidos        NVARCHAR(100)  NOT NULL,
        Direccion        NVARCHAR(200)  NOT NULL,
        Telefono         VARCHAR(20)    NOT NULL,
        Fecha_Nacimiento DATE           NOT NULL,
        CONSTRAINT PK_Clientes PRIMARY KEY (Id_cliente)
    );

    CREATE UNIQUE INDEX UX_Clientes_CUI ON dbo.Clientes (CUI);
END
GO

-- Datos de ejemplo
INSERT INTO dbo.Clientes (CUI, NIT, Nombres, Apellidos, Direccion, Telefono, Fecha_Nacimiento)
SELECT '2987654321010', '98765432K', N'María José', N'García Morales', N'Zona 10, Ciudad de Guatemala', '4123-4567', '2000-01-31'
WHERE NOT EXISTS (SELECT 1 FROM dbo.Clientes WHERE CUI = '2987654321010');
GO

SELECT * FROM dbo.Clientes;
GO
