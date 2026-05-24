
-- =========================================================================
-- 1. TABLAS MAESTRAS / INDEPENDIENTES
-- =========================================================================
use facturas;

CREATE TABLE usuarios (
    id_usuario INT NOT NULL AUTO_INCREMENT,
    usuario VARCHAR(50) NOT NULL UNIQUE,
    contra VARCHAR(50) NOT NULL,
    PRIMARY KEY (id_usuario)
) ENGINE=InnoDB;

CREATE TABLE marcas (
    id_marca SMALLINT NOT NULL AUTO_INCREMENT,
    marca VARCHAR(50) NOT NULL,
    PRIMARY KEY (id_marca)
) ENGINE=InnoDB;

CREATE TABLE proveedores (
    id_proveedor INT NOT NULL AUTO_INCREMENT,
    proveedor VARCHAR(60) NOT NULL,
    nit VARCHAR(12) NOT NULL,
    direccion VARCHAR(80) DEFAULT NULL,
    telefono VARCHAR(25) DEFAULT NULL,
    PRIMARY KEY (id_proveedor)
) ENGINE=InnoDB;

CREATE TABLE puestos (
    id_puesto SMALLINT NOT NULL AUTO_INCREMENT,
    puesto VARCHAR(50) NOT NULL,
    PRIMARY KEY (id_puesto)
) ENGINE=InnoDB;

CREATE TABLE clientes (
    id_cliente INT NOT NULL AUTO_INCREMENT,
    nombres VARCHAR(60) NOT NULL,
    apellidos VARCHAR(60) NOT NULL,
    nit VARCHAR(12) NOT NULL,
    genero BIT(1) DEFAULT NULL,
    telefono VARCHAR(25) DEFAULT NULL,
    correo_electronico VARCHAR(45) DEFAULT NULL,
    fecha_ingreso DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id_cliente)
) ENGINE=InnoDB;

-- =========================================================================
-- 2. TABLAS CON DEPENDENCIAS SIMPLES
-- =========================================================================

CREATE TABLE productos (
    id_producto INT NOT NULL AUTO_INCREMENT,
    producto VARCHAR(50) NOT NULL,
    id_marca SMALLINT NOT NULL,
    descripcion VARCHAR(100) DEFAULT NULL,
    imagen VARCHAR(30) DEFAULT NULL,
    precio_costo DECIMAL(8,2) NOT NULL,
    precio_venta DECIMAL(8,2) NOT NULL,
    existencia INT NOT NULL DEFAULT 0,
    fecha_ingreso DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id_producto),
    CONSTRAINT fk_productos_marcas 
        FOREIGN KEY (id_marca) REFERENCES marcas (id_marca)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;

CREATE TABLE compras (
    id_compra INT NOT NULL AUTO_INCREMENT,
    no_orden_compra INT NOT NULL,
    id_proveedor INT NOT NULL,
    fecha_orden DATE NOT NULL,
    fecha_ingreso DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id_compra),
    CONSTRAINT fk_compras_proveedores 
        FOREIGN KEY (id_proveedor) REFERENCES proveedores (id_proveedor)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;

CREATE TABLE empleados (
    id_empleado INT NOT NULL AUTO_INCREMENT,
    nombres VARCHAR(60) NOT NULL,
    apellidos VARCHAR(60) NOT NULL,
    direccion VARCHAR(80) DEFAULT NULL,
    telefono VARCHAR(25) DEFAULT NULL,
    cui VARCHAR(15) NOT NULL,
    genero BIT(1) DEFAULT NULL,
    fecha_nacimiento DATE NOT NULL,
    id_puesto SMALLINT NOT NULL,
    fecha_inicio_labores DATE NOT NULL,
    fecha_ingreso DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id_empleado),
    CONSTRAINT fk_empleados_puestos 
        FOREIGN KEY (id_puesto) REFERENCES puestos (id_puesto)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;

-- =========================================================================
-- 3. TABLAS DE MOVIMIENTOS Y DETALLES
-- =========================================================================

CREATE TABLE ventas (
    id_venta INT NOT NULL AUTO_INCREMENT,
    no_factura INT NOT NULL,
    serie CHAR(1) NOT NULL,
    fecha_factura DATE NOT NULL,
    id_cliente INT NOT NULL,
    id_empleado INT NOT NULL,
    fecha_ingreso DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (id_venta),
    CONSTRAINT fk_ventas_clientes 
        FOREIGN KEY (id_cliente) REFERENCES clientes (id_cliente)
        ON UPDATE CASCADE ON DELETE RESTRICT,
    CONSTRAINT fk_ventas_empleados 
        FOREIGN KEY (id_empleado) REFERENCES empleados (id_empleado)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;

CREATE TABLE compras_detalle (
    id_compra_detalle BIGINT NOT NULL AUTO_INCREMENT,
    id_compra INT NOT NULL,
    id_producto INT NOT NULL,
    cantidad INT NOT NULL,
    precio_costo_unitario DECIMAL(8,2) NOT NULL,
    PRIMARY KEY (id_compra_detalle),
    CONSTRAINT fk_compras_detalle_compras 
        FOREIGN KEY (id_compra) REFERENCES compras (id_compra)
        ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT fk_compras_detalle_productos 
        FOREIGN KEY (id_producto) REFERENCES productos (id_producto)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;

CREATE TABLE ventas_detalle (
    id_venta_detalle BIGINT NOT NULL AUTO_INCREMENT,
    id_venta INT NOT NULL,
    id_producto INT NOT NULL,
    cantidad INT NOT NULL,
    precio_unitario DECIMAL(8,2) NOT NULL,
    PRIMARY KEY (id_venta_detalle),
    CONSTRAINT fk_ventas_detalle_ventas 
        FOREIGN KEY (id_venta) REFERENCES ventas (id_venta)
        ON UPDATE CASCADE ON DELETE CASCADE,
    CONSTRAINT fk_ventas_detalle_productos 
        FOREIGN KEY (id_producto) REFERENCES productos (id_producto)
        ON UPDATE CASCADE ON DELETE RESTRICT
) ENGINE=InnoDB;




