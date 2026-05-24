#pragma once

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    // CORRECCIÓN: clase renombrada de 'productos' a 'producto' para coincidir con contenido.h
    public ref class producto : public System::Windows::Forms::Form
    {
    private:
        String^ connectionString = "server=localhost;database=facturas;uid=root;pwd=12345;";

    public:
        producto(void)
        {
            InitializeComponent();
            ConfigurarTabla();
            CargarMarcas();
            CargarProveedores();
            CargarProductos();
        }

    protected:
        ~producto() { if (components) delete components; }

    private:
        int id_producto_sel = -1;

        System::Windows::Forms::Panel^ panel_inventario;
        System::Windows::Forms::Panel^ panel_ficha;
        System::Windows::Forms::Label^ lbl_titulo_inventario;
        System::Windows::Forms::Label^ lbl_titulo_ficha;
        System::Windows::Forms::Label^ lbl_producto;
        System::Windows::Forms::TextBox^ txt_producto;
        System::Windows::Forms::Label^ lbl_descripcion;
        System::Windows::Forms::TextBox^ txt_descripcion;
        System::Windows::Forms::Label^ lbl_marca;
        System::Windows::Forms::ComboBox^ cmb_marca;
        System::Windows::Forms::Label^ lbl_proveedor;
        System::Windows::Forms::ComboBox^ cmb_proveedor;
        System::Windows::Forms::Label^ lbl_existencia;
        System::Windows::Forms::TextBox^ txt_existencia;
        System::Windows::Forms::Label^ lbl_costo;
        System::Windows::Forms::TextBox^ txt_costo;
        System::Windows::Forms::Label^ lbl_venta;
        System::Windows::Forms::TextBox^ txt_venta;
        System::Windows::Forms::Label^ lbl_fecha_ingreso;
        System::Windows::Forms::DateTimePicker^ dtp_fecha_ingreso;
        System::Windows::Forms::Label^ lbl_imagen;
        System::Windows::Forms::TextBox^ txt_imagen;
        System::Windows::Forms::Button^ btn_guardar;
        System::Windows::Forms::Button^ btn_actualizar;
        System::Windows::Forms::Button^ btn_limpiar;
        System::Windows::Forms::Button^ btn_eliminar;
        System::Windows::Forms::DataGridView^ datos_producto;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panel_inventario = (gcnew System::Windows::Forms::Panel());
            this->datos_producto = (gcnew System::Windows::Forms::DataGridView());
            this->lbl_titulo_inventario = (gcnew System::Windows::Forms::Label());
            this->panel_ficha = (gcnew System::Windows::Forms::Panel());
            this->lbl_titulo_ficha = (gcnew System::Windows::Forms::Label());
            this->lbl_producto = (gcnew System::Windows::Forms::Label());
            this->txt_producto = (gcnew System::Windows::Forms::TextBox());
            this->lbl_descripcion = (gcnew System::Windows::Forms::Label());
            this->txt_descripcion = (gcnew System::Windows::Forms::TextBox());
            this->lbl_marca = (gcnew System::Windows::Forms::Label());
            this->cmb_marca = (gcnew System::Windows::Forms::ComboBox());
            this->lbl_proveedor = (gcnew System::Windows::Forms::Label());
            this->cmb_proveedor = (gcnew System::Windows::Forms::ComboBox());
            this->lbl_existencia = (gcnew System::Windows::Forms::Label());
            this->txt_existencia = (gcnew System::Windows::Forms::TextBox());
            this->lbl_costo = (gcnew System::Windows::Forms::Label());
            this->txt_costo = (gcnew System::Windows::Forms::TextBox());
            this->lbl_venta = (gcnew System::Windows::Forms::Label());
            this->txt_venta = (gcnew System::Windows::Forms::TextBox());
            this->lbl_fecha_ingreso = (gcnew System::Windows::Forms::Label());
            this->dtp_fecha_ingreso = (gcnew System::Windows::Forms::DateTimePicker());
            this->lbl_imagen = (gcnew System::Windows::Forms::Label());
            this->txt_imagen = (gcnew System::Windows::Forms::TextBox());
            this->btn_guardar = (gcnew System::Windows::Forms::Button());
            this->btn_actualizar = (gcnew System::Windows::Forms::Button());
            this->btn_limpiar = (gcnew System::Windows::Forms::Button());
            this->btn_eliminar = (gcnew System::Windows::Forms::Button());
            this->panel_inventario->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_producto))->BeginInit();
            this->panel_ficha->SuspendLayout();
            this->SuspendLayout();
            // 
            // panel_inventario
            // 
            this->panel_inventario->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->panel_inventario->Controls->Add(this->datos_producto);
            this->panel_inventario->Controls->Add(this->lbl_titulo_inventario);
            this->panel_inventario->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel_inventario->Location = System::Drawing::Point(0, 0);
            this->panel_inventario->Name = L"panel_inventario";
            this->panel_inventario->Size = System::Drawing::Size(530, 590);
            this->panel_inventario->TabIndex = 0;
            this->panel_inventario->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &producto::panel_inventario_Paint);
            // 
            // datos_producto
            // 
            this->datos_producto->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->datos_producto->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->datos_producto->Location = System::Drawing::Point(20, 60);
            this->datos_producto->Name = L"datos_producto";
            this->datos_producto->Size = System::Drawing::Size(490, 518);
            this->datos_producto->TabIndex = 1;
            this->datos_producto->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &producto::datos_producto_CellClick);
            this->datos_producto->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &producto::datos_producto_CellContentClick);
            // 
            // lbl_titulo_inventario
            // 
            this->lbl_titulo_inventario->AutoSize = true;
            this->lbl_titulo_inventario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
            this->lbl_titulo_inventario->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lbl_titulo_inventario->Location = System::Drawing::Point(15, 18);
            this->lbl_titulo_inventario->Name = L"lbl_titulo_inventario";
            this->lbl_titulo_inventario->Size = System::Drawing::Size(160, 25);
            this->lbl_titulo_inventario->TabIndex = 0;
            this->lbl_titulo_inventario->Text = L"Inventario Actual";
            // 
            // panel_ficha
            // 
            this->panel_ficha->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)),
                static_cast<System::Int32>(static_cast<System::Byte>(36)));
            this->panel_ficha->Controls->Add(this->lbl_titulo_ficha);
            this->panel_ficha->Controls->Add(this->lbl_producto);
            this->panel_ficha->Controls->Add(this->txt_producto);
            this->panel_ficha->Controls->Add(this->lbl_descripcion);
            this->panel_ficha->Controls->Add(this->txt_descripcion);
            this->panel_ficha->Controls->Add(this->lbl_marca);
            this->panel_ficha->Controls->Add(this->cmb_marca);
            this->panel_ficha->Controls->Add(this->lbl_proveedor);
            this->panel_ficha->Controls->Add(this->cmb_proveedor);
            this->panel_ficha->Controls->Add(this->lbl_existencia);
            this->panel_ficha->Controls->Add(this->txt_existencia);
            this->panel_ficha->Controls->Add(this->lbl_costo);
            this->panel_ficha->Controls->Add(this->txt_costo);
            this->panel_ficha->Controls->Add(this->lbl_venta);
            this->panel_ficha->Controls->Add(this->txt_venta);
            this->panel_ficha->Controls->Add(this->lbl_fecha_ingreso);
            this->panel_ficha->Controls->Add(this->dtp_fecha_ingreso);
            this->panel_ficha->Controls->Add(this->lbl_imagen);
            this->panel_ficha->Controls->Add(this->txt_imagen);
            this->panel_ficha->Controls->Add(this->btn_guardar);
            this->panel_ficha->Controls->Add(this->btn_actualizar);
            this->panel_ficha->Controls->Add(this->btn_limpiar);
            this->panel_ficha->Controls->Add(this->btn_eliminar);
            this->panel_ficha->Dock = System::Windows::Forms::DockStyle::Right;
            this->panel_ficha->Location = System::Drawing::Point(530, 0);
            this->panel_ficha->Name = L"panel_ficha";
            this->panel_ficha->Size = System::Drawing::Size(470, 590);
            this->panel_ficha->TabIndex = 1;
            // 
            // lbl_titulo_ficha
            // 
            this->lbl_titulo_ficha->AutoSize = true;
            this->lbl_titulo_ficha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 13, System::Drawing::FontStyle::Bold));
            this->lbl_titulo_ficha->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lbl_titulo_ficha->Location = System::Drawing::Point(15, 18);
            this->lbl_titulo_ficha->Name = L"lbl_titulo_ficha";
            this->lbl_titulo_ficha->Size = System::Drawing::Size(124, 25);
            this->lbl_titulo_ficha->TabIndex = 0;
            this->lbl_titulo_ficha->Text = L"Ficha Técnica";
            // 
            // lbl_producto
            // 
            this->lbl_producto->AutoSize = true;
            this->lbl_producto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_producto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_producto->Location = System::Drawing::Point(15, 60);
            this->lbl_producto->Name = L"lbl_producto";
            this->lbl_producto->Size = System::Drawing::Size(66, 13);
            this->lbl_producto->TabIndex = 1;
            this->lbl_producto->Text = L"PRODUCTO";
            // 
            // txt_producto
            // 
            this->txt_producto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_producto->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_producto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_producto->ForeColor = System::Drawing::Color::White;
            this->txt_producto->Location = System::Drawing::Point(15, 77);
            this->txt_producto->Name = L"txt_producto";
            this->txt_producto->Size = System::Drawing::Size(435, 25);
            this->txt_producto->TabIndex = 2;
            // 
            // lbl_descripcion
            // 
            this->lbl_descripcion->AutoSize = true;
            this->lbl_descripcion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_descripcion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_descripcion->Location = System::Drawing::Point(15, 112);
            this->lbl_descripcion->Name = L"lbl_descripcion";
            this->lbl_descripcion->Size = System::Drawing::Size(78, 13);
            this->lbl_descripcion->TabIndex = 3;
            this->lbl_descripcion->Text = L"DESCRIPCIÓN";
            // 
            // txt_descripcion
            // 
            this->txt_descripcion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_descripcion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_descripcion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_descripcion->ForeColor = System::Drawing::Color::White;
            this->txt_descripcion->Location = System::Drawing::Point(15, 129);
            this->txt_descripcion->Name = L"txt_descripcion";
            this->txt_descripcion->Size = System::Drawing::Size(435, 25);
            this->txt_descripcion->TabIndex = 4;
            // 
            // lbl_marca
            // 
            this->lbl_marca->AutoSize = true;
            this->lbl_marca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_marca->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_marca->Location = System::Drawing::Point(15, 165);
            this->lbl_marca->Name = L"lbl_marca";
            this->lbl_marca->Size = System::Drawing::Size(48, 13);
            this->lbl_marca->TabIndex = 5;
            this->lbl_marca->Text = L"MARCA";
            // 
            // cmb_marca
            // 
            this->cmb_marca->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->cmb_marca->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmb_marca->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->cmb_marca->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmb_marca->ForeColor = System::Drawing::Color::White;
            this->cmb_marca->Location = System::Drawing::Point(15, 182);
            this->cmb_marca->Name = L"cmb_marca";
            this->cmb_marca->Size = System::Drawing::Size(135, 25);
            this->cmb_marca->TabIndex = 6;
            // 
            // lbl_proveedor
            // 
            this->lbl_proveedor->AutoSize = true;
            this->lbl_proveedor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_proveedor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_proveedor->Location = System::Drawing::Point(160, 165);
            this->lbl_proveedor->Name = L"lbl_proveedor";
            this->lbl_proveedor->Size = System::Drawing::Size(71, 13);
            this->lbl_proveedor->TabIndex = 7;
            this->lbl_proveedor->Text = L"PROVEEDOR";
            // 
            // cmb_proveedor
            // 
            this->cmb_proveedor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->cmb_proveedor->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmb_proveedor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->cmb_proveedor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmb_proveedor->ForeColor = System::Drawing::Color::White;
            this->cmb_proveedor->Location = System::Drawing::Point(160, 182);
            this->cmb_proveedor->Name = L"cmb_proveedor";
            this->cmb_proveedor->Size = System::Drawing::Size(155, 25);
            this->cmb_proveedor->TabIndex = 8;
            // 
            // lbl_existencia
            // 
            this->lbl_existencia->AutoSize = true;
            this->lbl_existencia->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_existencia->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_existencia->Location = System::Drawing::Point(325, 165);
            this->lbl_existencia->Name = L"lbl_existencia";
            this->lbl_existencia->Size = System::Drawing::Size(68, 13);
            this->lbl_existencia->TabIndex = 9;
            this->lbl_existencia->Text = L"EXISTENCIA";
            // 
            // txt_existencia
            // 
            this->txt_existencia->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_existencia->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_existencia->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_existencia->ForeColor = System::Drawing::Color::White;
            this->txt_existencia->Location = System::Drawing::Point(325, 182);
            this->txt_existencia->Name = L"txt_existencia";
            this->txt_existencia->Size = System::Drawing::Size(125, 25);
            this->txt_existencia->TabIndex = 10;
            // 
            // lbl_costo
            // 
            this->lbl_costo->AutoSize = true;
            this->lbl_costo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_costo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_costo->Location = System::Drawing::Point(15, 218);
            this->lbl_costo->Name = L"lbl_costo";
            this->lbl_costo->Size = System::Drawing::Size(42, 13);
            this->lbl_costo->TabIndex = 11;
            this->lbl_costo->Text = L"COSTO";
            // 
            // txt_costo
            // 
            this->txt_costo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_costo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_costo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_costo->ForeColor = System::Drawing::Color::White;
            this->txt_costo->Location = System::Drawing::Point(15, 235);
            this->txt_costo->Name = L"txt_costo";
            this->txt_costo->Size = System::Drawing::Size(135, 25);
            this->txt_costo->TabIndex = 12;
            // 
            // lbl_venta
            // 
            this->lbl_venta->AutoSize = true;
            this->lbl_venta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_venta->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_venta->Location = System::Drawing::Point(160, 218);
            this->lbl_venta->Name = L"lbl_venta";
            this->lbl_venta->Size = System::Drawing::Size(42, 13);
            this->lbl_venta->TabIndex = 13;
            this->lbl_venta->Text = L"VENTA";
            // 
            // txt_venta
            // 
            this->txt_venta->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_venta->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_venta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_venta->ForeColor = System::Drawing::Color::White;
            this->txt_venta->Location = System::Drawing::Point(160, 235);
            this->txt_venta->Name = L"txt_venta";
            this->txt_venta->Size = System::Drawing::Size(135, 25);
            this->txt_venta->TabIndex = 14;
            // 
            // lbl_fecha_ingreso
            // 
            this->lbl_fecha_ingreso->AutoSize = true;
            this->lbl_fecha_ingreso->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_fecha_ingreso->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_fecha_ingreso->Location = System::Drawing::Point(305, 218);
            this->lbl_fecha_ingreso->Name = L"lbl_fecha_ingreso";
            this->lbl_fecha_ingreso->Size = System::Drawing::Size(92, 13);
            this->lbl_fecha_ingreso->TabIndex = 15;
            this->lbl_fecha_ingreso->Text = L"FECHA INGRESO";
            // 
            // dtp_fecha_ingreso
            // 
            this->dtp_fecha_ingreso->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dtp_fecha_ingreso->Location = System::Drawing::Point(305, 235);
            this->dtp_fecha_ingreso->Name = L"dtp_fecha_ingreso";
            this->dtp_fecha_ingreso->Size = System::Drawing::Size(145, 20);
            this->dtp_fecha_ingreso->TabIndex = 16;
            // 
            // lbl_imagen
            // 
            this->lbl_imagen->AutoSize = true;
            this->lbl_imagen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_imagen->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_imagen->Location = System::Drawing::Point(15, 272);
            this->lbl_imagen->Name = L"lbl_imagen";
            this->lbl_imagen->Size = System::Drawing::Size(100, 13);
            this->lbl_imagen->TabIndex = 17;
            this->lbl_imagen->Text = L"RUTA DE IMAGEN";
            // 
            // txt_imagen
            // 
            this->txt_imagen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_imagen->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_imagen->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_imagen->ForeColor = System::Drawing::Color::White;
            this->txt_imagen->Location = System::Drawing::Point(15, 289);
            this->txt_imagen->Name = L"txt_imagen";
            this->txt_imagen->Size = System::Drawing::Size(435, 25);
            this->txt_imagen->TabIndex = 18;
            // 
            // btn_guardar
            // 
            this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_guardar->FlatAppearance->BorderSize = 0;
            this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_guardar->ForeColor = System::Drawing::Color::White;
            this->btn_guardar->Location = System::Drawing::Point(15, 340);
            this->btn_guardar->Name = L"btn_guardar";
            this->btn_guardar->Size = System::Drawing::Size(210, 40);
            this->btn_guardar->TabIndex = 19;
            this->btn_guardar->Text = L"Guardar";
            this->btn_guardar->UseVisualStyleBackColor = false;
            this->btn_guardar->Click += gcnew System::EventHandler(this, &producto::btn_guardar_Click);
            // 
            // btn_actualizar
            // 
            this->btn_actualizar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
                static_cast<System::Int32>(static_cast<System::Byte>(89)));
            this->btn_actualizar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_actualizar->FlatAppearance->BorderSize = 0;
            this->btn_actualizar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_actualizar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_actualizar->ForeColor = System::Drawing::Color::White;
            this->btn_actualizar->Location = System::Drawing::Point(240, 340);
            this->btn_actualizar->Name = L"btn_actualizar";
            this->btn_actualizar->Size = System::Drawing::Size(210, 40);
            this->btn_actualizar->TabIndex = 20;
            this->btn_actualizar->Text = L"Actualizar";
            this->btn_actualizar->UseVisualStyleBackColor = false;
            this->btn_actualizar->Click += gcnew System::EventHandler(this, &producto::btn_actualizar_Click);
            // 
            // btn_limpiar
            // 
            this->btn_limpiar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)));
            this->btn_limpiar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_limpiar->FlatAppearance->BorderSize = 0;
            this->btn_limpiar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_limpiar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_limpiar->ForeColor = System::Drawing::Color::White;
            this->btn_limpiar->Location = System::Drawing::Point(15, 393);
            this->btn_limpiar->Name = L"btn_limpiar";
            this->btn_limpiar->Size = System::Drawing::Size(210, 40);
            this->btn_limpiar->TabIndex = 21;
            this->btn_limpiar->Text = L"Limpiar";
            this->btn_limpiar->UseVisualStyleBackColor = false;
            this->btn_limpiar->Click += gcnew System::EventHandler(this, &producto::btn_limpiar_Click);
            // 
            // btn_eliminar
            // 
            this->btn_eliminar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
                static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->btn_eliminar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_eliminar->FlatAppearance->BorderSize = 0;
            this->btn_eliminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_eliminar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_eliminar->ForeColor = System::Drawing::Color::White;
            this->btn_eliminar->Location = System::Drawing::Point(240, 393);
            this->btn_eliminar->Name = L"btn_eliminar";
            this->btn_eliminar->Size = System::Drawing::Size(210, 40);
            this->btn_eliminar->TabIndex = 22;
            this->btn_eliminar->Text = L"Eliminar";
            this->btn_eliminar->UseVisualStyleBackColor = false;
            this->btn_eliminar->Click += gcnew System::EventHandler(this, &producto::btn_eliminar_Click);
            // 
            // producto
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            this->ClientSize = System::Drawing::Size(1000, 590);
            this->Controls->Add(this->panel_inventario);
            this->Controls->Add(this->panel_ficha);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"producto";
            this->Text = L"Módulo de Productos";
            this->panel_inventario->ResumeLayout(false);
            this->panel_inventario->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_producto))->EndInit();
            this->panel_ficha->ResumeLayout(false);
            this->panel_ficha->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        // ============================================================
        //  HELPERS
        // ============================================================
    private:
        void ConfigurarTabla() {
            datos_producto->ColumnCount = 7;
            datos_producto->Columns[0]->Name = L"ID";
            datos_producto->Columns[1]->Name = L"Producto";
            datos_producto->Columns[2]->Name = L"Marca";
            datos_producto->Columns[3]->Name = L"Precio Costo";
            datos_producto->Columns[4]->Name = L"Precio Venta";
            datos_producto->Columns[5]->Name = L"Existencia";
            datos_producto->Columns[6]->Name = L"Fecha Ingreso";
            datos_producto->Columns[0]->Width = 35;
            datos_producto->Columns[1]->Width = 145;
            datos_producto->Columns[2]->Width = 80;
            datos_producto->Columns[3]->Width = 85;
            datos_producto->Columns[4]->Width = 85;
            datos_producto->Columns[5]->Width = 70;
            datos_producto->Columns[6]->Width = 100;
            datos_producto->AllowUserToAddRows = false;
            datos_producto->RowHeadersVisible = false;
            datos_producto->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            datos_producto->EnableHeadersVisualStyles = false;
            datos_producto->ReadOnly = true;
            datos_producto->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 30, 45);
            datos_producto->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
            datos_producto->ColumnHeadersDefaultCellStyle->Font =
                (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            datos_producto->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(40, 40, 52);
            datos_producto->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
            datos_producto->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(0, 122, 255);
            datos_producto->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(35, 35, 48);
            datos_producto->AlternatingRowsDefaultCellStyle->ForeColor = System::Drawing::Color::White;
        }

        void CargarMarcas() {
            cmb_marca->Items->Clear();
            cmb_marca->Items->Add(L"-- Seleccionar --");
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT id_marca, marca FROM marcas ORDER BY marca", con);
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                while (dr->Read())
                    cmb_marca->Items->Add(dr["marca"]->ToString());
                dr->Close();
                con->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar marcas:\n" + ex->Message);
            }
            cmb_marca->SelectedIndex = 0;
        }

        void CargarProveedores() {
            cmb_proveedor->Items->Clear();
            cmb_proveedor->Items->Add(L"-- Seleccionar --");
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT id_proveedor, proveedor FROM proveedores ORDER BY proveedor", con);
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                while (dr->Read())
                    cmb_proveedor->Items->Add(dr["proveedor"]->ToString());
                dr->Close();
                con->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar proveedores:\n" + ex->Message);
            }
            cmb_proveedor->SelectedIndex = 0;
        }

        void CargarProductos() {
            datos_producto->Rows->Clear();
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "SELECT p.id_producto, p.producto, m.marca, "
                    "p.precio_costo, p.precio_venta, p.existencia, p.fecha_ingreso "
                    "FROM productos p "
                    "LEFT JOIN marcas m ON p.id_marca = m.id_marca "
                    "ORDER BY p.producto";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                while (dr->Read()) {
                    datos_producto->Rows->Add(
                        dr["id_producto"]->ToString(),
                        dr["producto"]->ToString(),
                        dr["marca"]->ToString(),
                        String::Format("Q {0:N2}", dr["precio_costo"]),
                        String::Format("Q {0:N2}", dr["precio_venta"]),
                        dr["existencia"]->ToString(),
                        Convert::ToDateTime(dr["fecha_ingreso"]).ToString("dd/MM/yyyy")
                    );
                }
                dr->Close();
                con->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar productos:\n" + ex->Message);
            }
        }

        int ObtenerIdMarca(String^ nombre) {
            int id = -1;  // -1 = sin marca
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT id_marca FROM marcas WHERE marca=@m LIMIT 1", con);
                cmd->Parameters->AddWithValue("@m", nombre);
                con->Open();
                Object^ res = cmd->ExecuteScalar();
                if (res != nullptr) id = Convert::ToInt32(res);
                con->Close();
            }
            catch (...) {}
            return id;
        }

        void Limpiar() {
            txt_producto->Text = L"";
            txt_descripcion->Text = L"";
            txt_existencia->Text = L"";
            txt_costo->Text = L"";
            txt_venta->Text = L"";
            txt_imagen->Text = L"";
            dtp_fecha_ingreso->Value = System::DateTime::Now;
            cmb_marca->SelectedIndex = 0;
            cmb_proveedor->SelectedIndex = 0;
            id_producto_sel = -1;
        }

        // ============================================================
        //  EVENTOS
        // ============================================================

        System::Void datos_producto_CellClick(System::Object^ sender,
            System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0) return;
            DataGridViewRow^ row = datos_producto->Rows[e->RowIndex];
            id_producto_sel = Convert::ToInt32(row->Cells[0]->Value);
            txt_producto->Text = row->Cells[1]->Value->ToString();
            txt_existencia->Text = row->Cells[5]->Value->ToString();
            txt_costo->Text = row->Cells[3]->Value->ToString()->Replace("Q ", "")->Trim();
            txt_venta->Text = row->Cells[4]->Value->ToString()->Replace("Q ", "")->Trim();
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT p.descripcion, p.imagen, m.marca, p.fecha_ingreso "
                    "FROM productos p LEFT JOIN marcas m ON p.id_marca=m.id_marca "
                    "WHERE p.id_producto=@id", con);
                cmd->Parameters->AddWithValue("@id", id_producto_sel);
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                if (dr->Read()) {
                    txt_descripcion->Text = dr["descripcion"]->ToString();
                    txt_imagen->Text = dr["imagen"]->ToString();
                    String^ marca = dr["marca"]->ToString();
                    int idx = cmb_marca->Items->IndexOf(marca);
                    if (idx >= 0) cmb_marca->SelectedIndex = idx;
                    dtp_fecha_ingreso->Value = Convert::ToDateTime(dr["fecha_ingreso"]);
                }
                dr->Close();
                con->Close();
            }
            catch (...) {}
        }

        System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (txt_producto->Text->Trim() == L"") {
                MessageBox::Show(L"El nombre del producto es obligatorio.",
                    L"Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            double costo = 0, venta = 0;
            int    exis = 0;
            if (!Double::TryParse(txt_costo->Text, costo) ||
                !Double::TryParse(txt_venta->Text, venta) ||
                !Int32::TryParse(txt_existencia->Text, exis)) {
                MessageBox::Show(L"Costo, Venta y Existencia deben ser números.",
                    L"Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            int id_marca = (cmb_marca->SelectedIndex > 0)
                ? ObtenerIdMarca(cmb_marca->SelectedItem->ToString()) : -1;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "INSERT INTO productos "
                    "(producto,id_marca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) "
                    "VALUES(@prod,@marca,@desc,@img,@costo,@venta,@exis,@fecha)";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@prod", txt_producto->Text->Trim());
                cmd->Parameters->AddWithValue("@marca", id_marca);
                cmd->Parameters->AddWithValue("@desc", txt_descripcion->Text->Trim());
                cmd->Parameters->AddWithValue("@img", txt_imagen->Text->Trim());
                cmd->Parameters->AddWithValue("@costo", costo);
                cmd->Parameters->AddWithValue("@venta", venta);
                cmd->Parameters->AddWithValue("@exis", exis);
                cmd->Parameters->AddWithValue("@fecha", dtp_fecha_ingreso->Value.ToString("yyyy-MM-dd"));
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Producto guardado correctamente.",
                    L"Guardar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                Limpiar();
                CargarProductos();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al guardar:\n" + ex->Message);
            }
        }

        System::Void btn_actualizar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (id_producto_sel < 0) {
                MessageBox::Show(L"Selecciona un producto de la tabla primero.",
                    L"Actualizar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            double costo = 0, venta = 0;
            int    exis = 0;
            if (!Double::TryParse(txt_costo->Text, costo) ||
                !Double::TryParse(txt_venta->Text, venta) ||
                !Int32::TryParse(txt_existencia->Text, exis)) {
                MessageBox::Show(L"Costo, Venta y Existencia deben ser números.",
                    L"Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            int id_marca = (cmb_marca->SelectedIndex > 0)
                ? ObtenerIdMarca(cmb_marca->SelectedItem->ToString()) : 0;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "UPDATE productos SET "
                    "producto=@prod, id_marca=@marca, descripcion=@desc, imagen=@img, "
                    "precio_costo=@costo, precio_venta=@venta, existencia=@exis, "
                    "fecha_ingreso=@fecha WHERE id_producto=@id";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@prod", txt_producto->Text->Trim());
                cmd->Parameters->AddWithValue("@marca", id_marca);
                cmd->Parameters->AddWithValue("@desc", txt_descripcion->Text->Trim());
                cmd->Parameters->AddWithValue("@img", txt_imagen->Text->Trim());
                cmd->Parameters->AddWithValue("@costo", costo);
                cmd->Parameters->AddWithValue("@venta", venta);
                cmd->Parameters->AddWithValue("@exis", exis);
                cmd->Parameters->AddWithValue("@fecha", dtp_fecha_ingreso->Value.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@id", id_producto_sel);
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Producto actualizado.",
                    L"Actualizar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                Limpiar();
                CargarProductos();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al actualizar:\n" + ex->Message);
            }
        }

        System::Void btn_limpiar_Click(System::Object^ sender, System::EventArgs^ e) {
            Limpiar();
        }

        System::Void btn_eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (id_producto_sel < 0) {
                MessageBox::Show(L"Selecciona un producto de la tabla primero.",
                    L"Eliminar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            System::Windows::Forms::DialogResult res = MessageBox::Show(
                L"¿Deseas eliminar el producto seleccionado?\nEsta acción no se puede deshacer.",
                L"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (res != System::Windows::Forms::DialogResult::Yes) return;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "DELETE FROM productos WHERE id_producto=@id", con);
                cmd->Parameters->AddWithValue("@id", id_producto_sel);
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Producto eliminado.",
                    L"Eliminar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                Limpiar();
                CargarProductos();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al eliminar:\n" + ex->Message);
            }
        }

        System::Void panel_inventario_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e) {
        }
    private: System::Void datos_producto_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
};
}