#pragma once

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    // CORRECCIÓN: clase renombrada de 'clientes' a 'cliente' para coincidir con contenido.h
    public ref class cliente : public System::Windows::Forms::Form
    {
    private:
        String^ connectionString = "server=localhost;database=facturas;uid=root;pwd=12345;";

    public:
        cliente(void)
        {
            InitializeComponent();
            ConfigurarTabla();
            dtp_fecha->Value = System::DateTime::Now;
            CargarClientes();
        }

        // Permite recibir un NIT desde el formulario de facturacion
        void SetNitInicial(String^ nit_nuevo) {
            txt_nit->Text = nit_nuevo;
        }

    protected:
        ~cliente() { if (components) delete components; }

    private:
        int id_cliente_sel = -1;

        System::Windows::Forms::Panel^ panel_izq;
        System::Windows::Forms::Panel^ panel_der;
        System::Windows::Forms::Label^ lbl_titulo_directorio;
        System::Windows::Forms::TextBox^ txt_buscador;
        System::Windows::Forms::Button^ btn_buscar;
        System::Windows::Forms::Label^ lbl_titulo_datos;
        System::Windows::Forms::Label^ lbl_nit;
        System::Windows::Forms::TextBox^ txt_nit;
        System::Windows::Forms::Label^ lbl_fecha;
        System::Windows::Forms::DateTimePicker^ dtp_fecha;
        System::Windows::Forms::Label^ lbl_nombre;
        System::Windows::Forms::TextBox^ txt_nombre;
        System::Windows::Forms::Label^ lbl_direccion;
        System::Windows::Forms::TextBox^ txt_direccion;
        System::Windows::Forms::Label^ lbl_correo;
        System::Windows::Forms::TextBox^ txt_correo;
        System::Windows::Forms::Label^ lbl_telefono;
        System::Windows::Forms::Label^ lbl_opcional;
        System::Windows::Forms::TextBox^ txt_telefono;
        System::Windows::Forms::Label^ lbl_genero;
        System::Windows::Forms::ComboBox^ cmb_genero;
        System::Windows::Forms::Button^ btn_guardar;
        System::Windows::Forms::Button^ btn_actualizar;
        System::Windows::Forms::Button^ btn_limpiar;
        System::Windows::Forms::Button^ btn_eliminar;
        System::Windows::Forms::DataGridView^ datos_cliente;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panel_izq = (gcnew System::Windows::Forms::Panel());
            this->datos_cliente = (gcnew System::Windows::Forms::DataGridView());
            this->btn_buscar = (gcnew System::Windows::Forms::Button());
            this->txt_buscador = (gcnew System::Windows::Forms::TextBox());
            this->lbl_titulo_directorio = (gcnew System::Windows::Forms::Label());
            this->panel_der = (gcnew System::Windows::Forms::Panel());
            this->btn_eliminar = (gcnew System::Windows::Forms::Button());
            this->btn_limpiar = (gcnew System::Windows::Forms::Button());
            this->btn_actualizar = (gcnew System::Windows::Forms::Button());
            this->btn_guardar = (gcnew System::Windows::Forms::Button());
            this->cmb_genero = (gcnew System::Windows::Forms::ComboBox());
            this->lbl_genero = (gcnew System::Windows::Forms::Label());
            this->txt_telefono = (gcnew System::Windows::Forms::TextBox());
            this->lbl_opcional = (gcnew System::Windows::Forms::Label());
            this->lbl_telefono = (gcnew System::Windows::Forms::Label());
            this->txt_correo = (gcnew System::Windows::Forms::TextBox());
            this->lbl_correo = (gcnew System::Windows::Forms::Label());
            this->txt_direccion = (gcnew System::Windows::Forms::TextBox());
            this->lbl_direccion = (gcnew System::Windows::Forms::Label());
            this->txt_nombre = (gcnew System::Windows::Forms::TextBox());
            this->lbl_nombre = (gcnew System::Windows::Forms::Label());
            this->dtp_fecha = (gcnew System::Windows::Forms::DateTimePicker());
            this->lbl_fecha = (gcnew System::Windows::Forms::Label());
            this->txt_nit = (gcnew System::Windows::Forms::TextBox());
            this->lbl_nit = (gcnew System::Windows::Forms::Label());
            this->lbl_titulo_datos = (gcnew System::Windows::Forms::Label());
            this->panel_izq->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_cliente))->BeginInit();
            this->panel_der->SuspendLayout();
            this->SuspendLayout();
            // 
            // panel_izq
            // 
            this->panel_izq->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->panel_izq->Controls->Add(this->datos_cliente);
            this->panel_izq->Controls->Add(this->btn_buscar);
            this->panel_izq->Controls->Add(this->txt_buscador);
            this->panel_izq->Controls->Add(this->lbl_titulo_directorio);
            this->panel_izq->Dock = System::Windows::Forms::DockStyle::Left;
            this->panel_izq->Location = System::Drawing::Point(0, 0);
            this->panel_izq->Name = L"panel_izq";
            this->panel_izq->Size = System::Drawing::Size(360, 480);
            this->panel_izq->TabIndex = 1;
            // 
            // datos_cliente
            // 
            this->datos_cliente->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)),
                static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(35)));
            this->datos_cliente->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->datos_cliente->Location = System::Drawing::Point(15, 103);
            this->datos_cliente->Name = L"datos_cliente";
            this->datos_cliente->Size = System::Drawing::Size(326, 365);
            this->datos_cliente->TabIndex = 4;
            this->datos_cliente->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &cliente::datos_cliente_CellClick);
            // 
            // btn_buscar
            // 
            this->btn_buscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btn_buscar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_buscar->FlatAppearance->BorderSize = 0;
            this->btn_buscar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_buscar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btn_buscar->ForeColor = System::Drawing::Color::White;
            this->btn_buscar->Location = System::Drawing::Point(265, 49);
            this->btn_buscar->Name = L"btn_buscar";
            this->btn_buscar->Size = System::Drawing::Size(80, 27);
            this->btn_buscar->TabIndex = 1;
            this->btn_buscar->Text = L"Buscar";
            this->btn_buscar->UseVisualStyleBackColor = false;
            this->btn_buscar->Click += gcnew System::EventHandler(this, &cliente::btn_buscar_Click);
            // 
            // txt_buscador
            // 
            this->txt_buscador->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_buscador->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_buscador->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_buscador->ForeColor = System::Drawing::Color::White;
            this->txt_buscador->Location = System::Drawing::Point(15, 50);
            this->txt_buscador->Name = L"txt_buscador";
            this->txt_buscador->Size = System::Drawing::Size(240, 25);
            this->txt_buscador->TabIndex = 2;
            // 
            // lbl_titulo_directorio
            // 
            this->lbl_titulo_directorio->AutoSize = true;
            this->lbl_titulo_directorio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->lbl_titulo_directorio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lbl_titulo_directorio->Location = System::Drawing::Point(15, 15);
            this->lbl_titulo_directorio->Name = L"lbl_titulo_directorio";
            this->lbl_titulo_directorio->Size = System::Drawing::Size(191, 20);
            this->lbl_titulo_directorio->TabIndex = 3;
            this->lbl_titulo_directorio->Text = L"DIRECTORIO DE CLIENTES";
            // 
            // panel_der
            // 
            this->panel_der->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->panel_der->Controls->Add(this->btn_eliminar);
            this->panel_der->Controls->Add(this->btn_limpiar);
            this->panel_der->Controls->Add(this->btn_actualizar);
            this->panel_der->Controls->Add(this->btn_guardar);
            this->panel_der->Controls->Add(this->cmb_genero);
            this->panel_der->Controls->Add(this->lbl_genero);
            this->panel_der->Controls->Add(this->txt_telefono);
            this->panel_der->Controls->Add(this->lbl_opcional);
            this->panel_der->Controls->Add(this->lbl_telefono);
            this->panel_der->Controls->Add(this->txt_correo);
            this->panel_der->Controls->Add(this->lbl_correo);
            this->panel_der->Controls->Add(this->txt_direccion);
            this->panel_der->Controls->Add(this->lbl_direccion);
            this->panel_der->Controls->Add(this->txt_nombre);
            this->panel_der->Controls->Add(this->lbl_nombre);
            this->panel_der->Controls->Add(this->dtp_fecha);
            this->panel_der->Controls->Add(this->lbl_fecha);
            this->panel_der->Controls->Add(this->txt_nit);
            this->panel_der->Controls->Add(this->lbl_nit);
            this->panel_der->Controls->Add(this->lbl_titulo_datos);
            this->panel_der->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel_der->Location = System::Drawing::Point(360, 0);
            this->panel_der->Name = L"panel_der";
            this->panel_der->Size = System::Drawing::Size(351, 480);
            this->panel_der->TabIndex = 0;
            // 
            // btn_eliminar
            // 
            this->btn_eliminar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
                static_cast<System::Int32>(static_cast<System::Byte>(48)));
            this->btn_eliminar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_eliminar->FlatAppearance->BorderSize = 0;
            this->btn_eliminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_eliminar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btn_eliminar->ForeColor = System::Drawing::Color::White;
            this->btn_eliminar->Location = System::Drawing::Point(180, 420);
            this->btn_eliminar->Name = L"btn_eliminar";
            this->btn_eliminar->Size = System::Drawing::Size(150, 40);
            this->btn_eliminar->TabIndex = 0;
            this->btn_eliminar->Text = L"Eliminar";
            this->btn_eliminar->UseVisualStyleBackColor = false;
            this->btn_eliminar->Click += gcnew System::EventHandler(this, &cliente::btn_eliminar_Click);
            // 
            // btn_limpiar
            // 
            this->btn_limpiar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(69)));
            this->btn_limpiar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_limpiar->FlatAppearance->BorderSize = 0;
            this->btn_limpiar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_limpiar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btn_limpiar->ForeColor = System::Drawing::Color::White;
            this->btn_limpiar->Location = System::Drawing::Point(20, 420);
            this->btn_limpiar->Name = L"btn_limpiar";
            this->btn_limpiar->Size = System::Drawing::Size(150, 40);
            this->btn_limpiar->TabIndex = 1;
            this->btn_limpiar->Text = L"Limpiar";
            this->btn_limpiar->UseVisualStyleBackColor = false;
            this->btn_limpiar->Click += gcnew System::EventHandler(this, &cliente::btn_limpiar_Click);
            // 
            // btn_actualizar
            // 
            this->btn_actualizar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(199)),
                static_cast<System::Int32>(static_cast<System::Byte>(89)));
            this->btn_actualizar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_actualizar->FlatAppearance->BorderSize = 0;
            this->btn_actualizar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_actualizar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btn_actualizar->ForeColor = System::Drawing::Color::White;
            this->btn_actualizar->Location = System::Drawing::Point(180, 370);
            this->btn_actualizar->Name = L"btn_actualizar";
            this->btn_actualizar->Size = System::Drawing::Size(150, 40);
            this->btn_actualizar->TabIndex = 2;
            this->btn_actualizar->Text = L"Actualizar";
            this->btn_actualizar->UseVisualStyleBackColor = false;
            this->btn_actualizar->Click += gcnew System::EventHandler(this, &cliente::btn_actualizar_Click);
            // 
            // btn_guardar
            // 
            this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_guardar->FlatAppearance->BorderSize = 0;
            this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btn_guardar->ForeColor = System::Drawing::Color::White;
            this->btn_guardar->Location = System::Drawing::Point(20, 370);
            this->btn_guardar->Name = L"btn_guardar";
            this->btn_guardar->Size = System::Drawing::Size(150, 40);
            this->btn_guardar->TabIndex = 3;
            this->btn_guardar->Text = L"Guardar Nuevo";
            this->btn_guardar->UseVisualStyleBackColor = false;
            this->btn_guardar->Click += gcnew System::EventHandler(this, &cliente::btn_guardar_Click);
            // 
            // cmb_genero
            // 
            this->cmb_genero->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->cmb_genero->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmb_genero->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->cmb_genero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmb_genero->ForeColor = System::Drawing::Color::White;
            this->cmb_genero->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Masculino", L"Femenino", L"Empresa / N/A" });
            this->cmb_genero->Location = System::Drawing::Point(180, 308);
            this->cmb_genero->Name = L"cmb_genero";
            this->cmb_genero->Size = System::Drawing::Size(150, 25);
            this->cmb_genero->TabIndex = 4;
            // 
            // lbl_genero
            // 
            this->lbl_genero->AutoSize = true;
            this->lbl_genero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_genero->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_genero->Location = System::Drawing::Point(180, 290);
            this->lbl_genero->Name = L"lbl_genero";
            this->lbl_genero->Size = System::Drawing::Size(51, 13);
            this->lbl_genero->TabIndex = 5;
            this->lbl_genero->Text = L"GÉNERO";
            // 
            // txt_telefono
            // 
            this->txt_telefono->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_telefono->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_telefono->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_telefono->ForeColor = System::Drawing::Color::White;
            this->txt_telefono->Location = System::Drawing::Point(20, 308);
            this->txt_telefono->Name = L"txt_telefono";
            this->txt_telefono->Size = System::Drawing::Size(150, 25);
            this->txt_telefono->TabIndex = 6;
            // 
            // lbl_opcional
            // 
            this->lbl_opcional->AutoSize = true;
            this->lbl_opcional->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lbl_opcional->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
                static_cast<System::Int32>(static_cast<System::Byte>(120)));
            this->lbl_opcional->Location = System::Drawing::Point(85, 290);
            this->lbl_opcional->Name = L"lbl_opcional";
            this->lbl_opcional->Size = System::Drawing::Size(60, 13);
            this->lbl_opcional->TabIndex = 7;
            this->lbl_opcional->Text = L"(Opcional)";
            // 
            // lbl_telefono
            // 
            this->lbl_telefono->AutoSize = true;
            this->lbl_telefono->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_telefono->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_telefono->Location = System::Drawing::Point(20, 290);
            this->lbl_telefono->Name = L"lbl_telefono";
            this->lbl_telefono->Size = System::Drawing::Size(62, 13);
            this->lbl_telefono->TabIndex = 8;
            this->lbl_telefono->Text = L"TELÉFONO";
            // 
            // txt_correo
            // 
            this->txt_correo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_correo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_correo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_correo->ForeColor = System::Drawing::Color::White;
            this->txt_correo->Location = System::Drawing::Point(20, 248);
            this->txt_correo->Name = L"txt_correo";
            this->txt_correo->Size = System::Drawing::Size(310, 25);
            this->txt_correo->TabIndex = 9;
            // 
            // lbl_correo
            // 
            this->lbl_correo->AutoSize = true;
            this->lbl_correo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_correo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_correo->Location = System::Drawing::Point(20, 230);
            this->lbl_correo->Name = L"lbl_correo";
            this->lbl_correo->Size = System::Drawing::Size(126, 13);
            this->lbl_correo->TabIndex = 10;
            this->lbl_correo->Text = L"CORREO ELECTRÓNICO";
            // 
            // txt_direccion
            // 
            this->txt_direccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_direccion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_direccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_direccion->ForeColor = System::Drawing::Color::White;
            this->txt_direccion->Location = System::Drawing::Point(20, 188);
            this->txt_direccion->Name = L"txt_direccion";
            this->txt_direccion->Size = System::Drawing::Size(310, 25);
            this->txt_direccion->TabIndex = 11;
            // 
            // lbl_direccion
            // 
            this->lbl_direccion->AutoSize = true;
            this->lbl_direccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_direccion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_direccion->Location = System::Drawing::Point(20, 170);
            this->lbl_direccion->Name = L"lbl_direccion";
            this->lbl_direccion->Size = System::Drawing::Size(104, 13);
            this->lbl_direccion->TabIndex = 12;
            this->lbl_direccion->Text = L"DIRECCIÓN FISCAL";
            // 
            // txt_nombre
            // 
            this->txt_nombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_nombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_nombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_nombre->ForeColor = System::Drawing::Color::White;
            this->txt_nombre->Location = System::Drawing::Point(20, 128);
            this->txt_nombre->Name = L"txt_nombre";
            this->txt_nombre->Size = System::Drawing::Size(310, 25);
            this->txt_nombre->TabIndex = 13;
            // 
            // lbl_nombre
            // 
            this->lbl_nombre->AutoSize = true;
            this->lbl_nombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_nombre->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_nombre->Location = System::Drawing::Point(20, 110);
            this->lbl_nombre->Name = L"lbl_nombre";
            this->lbl_nombre->Size = System::Drawing::Size(208, 13);
            this->lbl_nombre->TabIndex = 14;
            this->lbl_nombre->Text = L"NOMBRE COMPLETO / RAZÓN SOCIAL";
            // 
            // dtp_fecha
            // 
            this->dtp_fecha->Enabled = true;
            this->dtp_fecha->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dtp_fecha->Location = System::Drawing::Point(180, 68);
            this->dtp_fecha->Name = L"dtp_fecha";
            this->dtp_fecha->Size = System::Drawing::Size(150, 20);
            this->dtp_fecha->TabIndex = 15;
            // 
            // lbl_fecha
            // 
            this->lbl_fecha->AutoSize = true;
            this->lbl_fecha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_fecha->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_fecha->Location = System::Drawing::Point(180, 50);
            this->lbl_fecha->Name = L"lbl_fecha";
            this->lbl_fecha->Size = System::Drawing::Size(109, 13);
            this->lbl_fecha->TabIndex = 16;
            this->lbl_fecha->Text = L"FECHA DE INGRESO";
            // 
            // txt_nit
            // 
            this->txt_nit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_nit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_nit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_nit->ForeColor = System::Drawing::Color::White;
            this->txt_nit->Location = System::Drawing::Point(20, 68);
            this->txt_nit->Name = L"txt_nit";
            this->txt_nit->Size = System::Drawing::Size(150, 25);
            this->txt_nit->TabIndex = 17;
            // 
            // lbl_nit
            // 
            this->lbl_nit->AutoSize = true;
            this->lbl_nit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_nit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)),
                static_cast<System::Int32>(static_cast<System::Byte>(170)));
            this->lbl_nit->Location = System::Drawing::Point(20, 50);
            this->lbl_nit->Name = L"lbl_nit";
            this->lbl_nit->Size = System::Drawing::Size(25, 13);
            this->lbl_nit->TabIndex = 18;
            this->lbl_nit->Text = L"NIT";
            this->lbl_nit->Click += gcnew System::EventHandler(this, &cliente::lbl_nit_Click);
            // 
            // lbl_titulo_datos
            // 
            this->lbl_titulo_datos->AutoSize = true;
            this->lbl_titulo_datos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->lbl_titulo_datos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lbl_titulo_datos->Location = System::Drawing::Point(20, 15);
            this->lbl_titulo_datos->Name = L"lbl_titulo_datos";
            this->lbl_titulo_datos->Size = System::Drawing::Size(151, 20);
            this->lbl_titulo_datos->TabIndex = 19;
            this->lbl_titulo_datos->Text = L"DATOS DEL CLIENTE";
            // 
            // cliente
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(711, 480);
            this->Controls->Add(this->panel_der);
            this->Controls->Add(this->panel_izq);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"cliente";
            this->Text = L"Directorio de Clientes";
            this->panel_izq->ResumeLayout(false);
            this->panel_izq->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_cliente))->EndInit();
            this->panel_der->ResumeLayout(false);
            this->panel_der->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        // ============================================================
        //  HELPERS
        // ============================================================
    private:
        void ConfigurarTabla() {
            datos_cliente->ColumnCount = 4;
            datos_cliente->Columns[0]->Name = L"ID";
            datos_cliente->Columns[1]->Name = L"NIT";
            datos_cliente->Columns[2]->Name = L"Nombre Completo";
            datos_cliente->Columns[3]->Name = L"Teléfono";
            datos_cliente->Columns[0]->Width = 30;
            datos_cliente->Columns[1]->Width = 80;
            datos_cliente->Columns[2]->Width = 120;
            datos_cliente->Columns[3]->Width = 80;
            datos_cliente->AllowUserToAddRows = false;
            datos_cliente->RowHeadersVisible = false;
            datos_cliente->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            datos_cliente->EnableHeadersVisualStyles = false;
            datos_cliente->ReadOnly = true;
            datos_cliente->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 30, 45);
            datos_cliente->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
            datos_cliente->ColumnHeadersDefaultCellStyle->Font =
                (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            datos_cliente->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(25, 25, 35);
            datos_cliente->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
            datos_cliente->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(0, 122, 255);
            datos_cliente->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(32, 32, 44);
            datos_cliente->AlternatingRowsDefaultCellStyle->ForeColor = System::Drawing::Color::White;
        }

        void CargarClientes(String^ filtro) {
            datos_cliente->Rows->Clear();
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "SELECT id_cliente, nit, "
                    "CONCAT(nombres,' ',apellidos) AS nombre, telefono "
                    "FROM clientes "
                    "WHERE nit LIKE @f OR nombres LIKE @f OR apellidos LIKE @f "
                    "ORDER BY nombres";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@f", "%" + filtro + "%");
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                while (dr->Read()) {
                    String^ t_nit = dr->IsDBNull(dr->GetOrdinal("nit")) ? "" : dr->GetString("nit");
                    String^ t_tel = dr->IsDBNull(dr->GetOrdinal("telefono")) ? "" : dr->GetString("telefono");
                    datos_cliente->Rows->Add(
                        dr["id_cliente"]->ToString(),
                        t_nit,
                        dr["nombre"]->ToString(),
                        t_tel
                    );
                }
                dr->Close();
                con->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar clientes:\n" + ex->Message);
            }
        }

        void CargarClientes() { CargarClientes(L""); }

        void Limpiar() {
            txt_nit->Clear();
            txt_nombre->Clear();
            txt_direccion->Clear();
            txt_correo->Clear();
            txt_telefono->Clear();
            cmb_genero->SelectedIndex = -1;
            txt_buscador->Clear();
            dtp_fecha->Value = System::DateTime::Now;
            id_cliente_sel = -1;
            txt_nit->Focus();
        }

        // ============================================================
        //  EVENTOS
        // ============================================================

        System::Void datos_cliente_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0) return;
            int id = Convert::ToInt32(datos_cliente->Rows[e->RowIndex]->Cells[0]->Value);
            id_cliente_sel = id;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand("SELECT * FROM clientes WHERE id_cliente=@id", con);
                cmd->Parameters->AddWithValue("@id", id);
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                if (dr->Read()) {
                    txt_nit->Text = dr->IsDBNull(dr->GetOrdinal("nit")) ? "" : dr->GetString("nit");
                    String^ nombres = dr->IsDBNull(dr->GetOrdinal("nombres")) ? "" : dr->GetString("nombres");
                    String^ apellidos = dr->IsDBNull(dr->GetOrdinal("apellidos")) ? "" : dr->GetString("apellidos");
                    txt_nombre->Text = (nombres + " " + apellidos)->Trim();
                    txt_direccion->Text = dr->IsDBNull(dr->GetOrdinal("direccion")) ? "" : dr->GetString("direccion");
                    txt_correo->Text = dr->IsDBNull(dr->GetOrdinal("correo_electronico")) ? "" : dr->GetString("correo_electronico");
                    txt_telefono->Text = dr->IsDBNull(dr->GetOrdinal("telefono")) ? "" : dr->GetString("telefono");
                    if (!dr->IsDBNull(dr->GetOrdinal("fecha_ingreso")))
                        dtp_fecha->Value = dr->GetDateTime("fecha_ingreso");
                    if (!dr->IsDBNull(dr->GetOrdinal("genero")))
                        cmb_genero->SelectedIndex = dr->GetBoolean("genero") ? 0 : 1;
                    else
                        cmb_genero->SelectedIndex = 2;
                }
                dr->Close();
                con->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar detalles:\n" + ex->Message);
            }
        }

        System::Void btn_buscar_Click(System::Object^ sender, System::EventArgs^ e) {
            CargarClientes(txt_buscador->Text->Trim());
        }

        System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (txt_nit->Text->Trim() == L"" || txt_nombre->Text->Trim() == L"") {
                MessageBox::Show(L"El NIT y el Nombre son obligatorios.",
                    L"Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            // Separar nombre y apellido (ultima palabra = apellido)
            array<String^>^ partes = txt_nombre->Text->Trim()->Split(' ');
            String^ nombres = txt_nombre->Text->Trim();
            String^ apellidos = L"";
            if (partes->Length > 1) {
                apellidos = partes[partes->Length - 1];
                nombres = nombres->Substring(0, nombres->Length - apellidos->Length - 1);
            }
            bool genero = (cmb_genero->SelectedIndex == 0);
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "INSERT INTO clientes "
                    "(nombres,apellidos,nit,genero,telefono,correo_electronico,direccion,fecha_ingreso) "
                    "VALUES(@n,@a,@nit,@gen,@tel,@correo,@dir,NOW())";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@n", nombres);
                cmd->Parameters->AddWithValue("@a", apellidos);
                cmd->Parameters->AddWithValue("@nit", txt_nit->Text->Trim());
                cmd->Parameters->AddWithValue("@gen", genero ? 1 : 0);
                cmd->Parameters->AddWithValue("@tel", txt_telefono->Text->Trim());
                cmd->Parameters->AddWithValue("@correo", txt_correo->Text->Trim());
                cmd->Parameters->AddWithValue("@dir", txt_direccion->Text->Trim());
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Cliente guardado correctamente.",
                    L"Guardar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                Limpiar();
                CargarClientes();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al guardar:\n" + ex->Message);
            }
        }

        System::Void btn_actualizar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (id_cliente_sel < 0) {
                MessageBox::Show(L"Selecciona un cliente de la tabla.",
                    L"Actualizar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            array<String^>^ partes = txt_nombre->Text->Trim()->Split(' ');
            String^ nombres = txt_nombre->Text->Trim();
            String^ apellidos = L"";
            if (partes->Length > 1) {
                apellidos = partes[partes->Length - 1];
                nombres = nombres->Substring(0, nombres->Length - apellidos->Length - 1);
            }
            bool genero = (cmb_genero->SelectedIndex == 0);
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "UPDATE clientes SET "
                    "nombres=@n, apellidos=@a, nit=@nit, genero=@gen, "
                    "telefono=@tel, correo_electronico=@correo, direccion=@dir "
                    "WHERE id_cliente=@id";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@n", nombres);
                cmd->Parameters->AddWithValue("@a", apellidos);
                cmd->Parameters->AddWithValue("@nit", txt_nit->Text->Trim());
                cmd->Parameters->AddWithValue("@gen", genero ? 1 : 0);
                cmd->Parameters->AddWithValue("@tel", txt_telefono->Text->Trim());
                cmd->Parameters->AddWithValue("@correo", txt_correo->Text->Trim());
                cmd->Parameters->AddWithValue("@dir", txt_direccion->Text->Trim());
                cmd->Parameters->AddWithValue("@id", id_cliente_sel);
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Cliente actualizado.",
                    L"Actualizar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                Limpiar();
                CargarClientes();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al actualizar:\n" + ex->Message);
            }
        }

        System::Void btn_limpiar_Click(System::Object^ sender, System::EventArgs^ e) {
            Limpiar();
        }

        System::Void btn_eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (id_cliente_sel < 0) {
                MessageBox::Show(L"Selecciona un cliente de la tabla.",
                    L"Eliminar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            System::Windows::Forms::DialogResult res = MessageBox::Show(
                L"¿Deseas eliminar este cliente permanentemente?",
                L"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (res != System::Windows::Forms::DialogResult::Yes) return;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "DELETE FROM clientes WHERE id_cliente=@id", con);
                cmd->Parameters->AddWithValue("@id", id_cliente_sel);
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Cliente eliminado.",
                    L"Eliminar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                Limpiar();
                CargarClientes();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al eliminar:\n" + ex->Message);
            }
        }
    private: System::Void lbl_nit_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}