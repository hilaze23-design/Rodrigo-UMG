-- =====================================================================
-- PUNTO 1 - Modificacion de la tabla clientes YA EXISTENTE
-- Use este script si NO quiere borrar los datos que ya tiene.
-- =====================================================================

USE db_empresa_programacion1;

ALTER TABLE clientes
    ADD COLUMN activo                 BIT      NOT NULL DEFAULT 1,
    ADD COLUMN fecha_ingreso_registro DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    ADD COLUMN fecha_eliminacion      DATETIME NULL     DEFAULT NULL;

-- Deja todos los registros que ya existian como clientes activos
UPDATE clientes
SET activo = 1,
    fecha_eliminacion = NULL
WHERE activo IS NULL OR activo = 0;

-- Verificacion de la estructura
DESCRIBE clientes;
