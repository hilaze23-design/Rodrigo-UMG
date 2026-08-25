-- =====================================================================
-- Proyecto : java_escritorio1 - CRUD de Clientes
-- Base de datos: db_empresa_programacion1  (MySQL / MariaDB)
-- Autor    : Carlos Alberto Mendez Giron
-- Carnet   : 4820-25-11347
-- ---------------------------------------------------------------------
-- SCRIPT COMPLETO: crea la base de datos desde cero, ya con los campos
-- activo, fecha_ingreso_registro y fecha_eliminacion.
-- Si ya tiene la base creada, use en su lugar: alter_clientes.sql
-- =====================================================================

DROP DATABASE IF EXISTS db_empresa_programacion1;
CREATE DATABASE db_empresa_programacion1
    DEFAULT CHARACTER SET utf8mb4
    DEFAULT COLLATE utf8mb4_general_ci;

USE db_empresa_programacion1;

-- ---------------------------------------------------------------------
-- PUNTO 1: tabla clientes con los tres campos nuevos
-- ---------------------------------------------------------------------
CREATE TABLE clientes (
    id_cliente              INT           NOT NULL AUTO_INCREMENT,
    cui                     VARCHAR(20)   NOT NULL,
    nit                     VARCHAR(20)   NOT NULL,
    nombres                 VARCHAR(60)   NOT NULL,
    apellidos               VARCHAR(60)   NOT NULL,
    direccion               VARCHAR(150)  NULL,
    telefono                VARCHAR(20)   NULL,
    fecha_nacimiento        DATE          NULL,

    -- === CAMPOS NUEVOS ===
    activo                  BIT           NOT NULL DEFAULT 1,
    fecha_ingreso_registro  DATETIME      NOT NULL DEFAULT CURRENT_TIMESTAMP,
    fecha_eliminacion       DATETIME      NULL     DEFAULT NULL,

    PRIMARY KEY (id_cliente)
) ENGINE=InnoDB;

-- ---------------------------------------------------------------------
-- Datos de ejemplo (nombres genericos)
-- activo = 1, fecha_ingreso_registro = NOW(), fecha_eliminacion = NULL
-- ---------------------------------------------------------------------
INSERT INTO clientes
    (cui, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento, activo, fecha_ingreso_registro, fecha_eliminacion)
VALUES
    ('2547896320101', '85471236', 'Mario Antonio',  'Gutierrez Pineda',  '4a Calle 12-45 Zona 1, Guatemala',   '55412398', '1995-03-14', 1, NOW(), NULL),
    ('3125478960102', '74125896', 'Lucia Fernanda', 'Ramirez Solares',   '6a Avenida 8-20 Zona 10, Guatemala', '42871560', '1998-11-02', 1, NOW(), NULL),
    ('1896325470103', '69874125', 'Diego Armando',  'Castillo Morales',  'Calzada Roosevelt 15-33 Zona 7',     '58963214', '1992-07-25', 1, NOW(), NULL),
    ('4587963210104', '32541789', 'Andrea Sofia',   'Herrera Batres',    '2a Calle 5-18 Zona 15, Guatemala',   '47125896', '2000-01-30', 1, NOW(), NULL),
    ('7412589630105', '15987436', 'Roberto Emilio', 'Vasquez Alvarado',  '9a Avenida 3-27 Zona 4, Mixco',      '53698741', '1988-09-08', 1, NOW(), NULL);

-- Ejemplo de un registro ya dado de baja logicamente:
-- permanece en la tabla pero NO aparece en el listado del sistema.
INSERT INTO clientes
    (cui, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento, activo, fecha_ingreso_registro, fecha_eliminacion)
VALUES
    ('9638527410106', '78945612', 'Silvia Marlene', 'Ortiz Recinos', '1a Calle 7-11 Zona 2, Villa Nueva', '41236987', '1990-05-19', 0, NOW(), NOW());

-- ---------------------------------------------------------------------
-- Comprobaciones
-- ---------------------------------------------------------------------
-- Lo que muestra el sistema (metodo leer): solo activos
SELECT id_cliente, cui, nit, nombres, apellidos, direccion, telefono, fecha_nacimiento
FROM clientes WHERE activo = 1 ORDER BY id_cliente;

-- Todo lo que realmente sigue guardado en la tabla
SELECT id_cliente, nombres, apellidos, activo, fecha_ingreso_registro, fecha_eliminacion FROM clientes;
