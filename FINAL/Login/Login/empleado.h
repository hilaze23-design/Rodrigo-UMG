#pragma once

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class empleado : public System::Windows::Forms::Form
    {
    private:
        String^ connectionString = "server=localhost;database=facturas;uid=root;pwd=12345;";

    public:
        empleado(void)
        {
            InitializeComponent();
            CargarPuestosDB();
            txt_fecha_ingreso->Text = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
            ConfigurarTabla();
            CargarEmpleados();
        }

    protected:
        ~empleado() { if (components) delete components; }

    private:
        int id_empleado_sel = -1;

        System::Windows::Forms::Panel^ panel_directorio;
        System::Windows::Forms::Label^ lbl_titulo_dir;
        System::Windows::Forms::TextBox^ txt_buscar;
        System::Windows::Forms::Label^ lbl_col_header;
        System::Windows::Forms::Panel^ panel_ficha;
        System::Windows::Forms::Label^ lbl_titulo_ficha;
        System::Windows::Forms::Label^ lbl_cui;
        System::Windows::Forms::TextBox^ txt_cui;
        System::Windows::Forms::Label^ lbl_genero;
        System::Windows::Forms::RadioButton^ rb_masculino;
        System::Windows::Forms::RadioButton^ rb_femenino;
        System::Windows::Forms::Label^ lbl_nombres;
        System::Windows::Forms::TextBox^ txt_nombres;
        System::Windows::Forms::Label^ lbl_apellidos;
        System::Windows::Forms::TextBox^ txt_apellidos;
        System::Windows::Forms::Label^ lbl_fecha_nac;
        System::Windows::Forms::DateTimePicker^ dtp_fecha_nac;
        System::Windows::Forms::Label^ lbl_telefono;
        System::Windows::Forms::TextBox^ txt_telefono;
        System::Windows::Forms::Label^ lbl_direccion;
        System::Windows::Forms::TextBox^ txt_direccion;
        System::Windows::Forms::Label^ lbl_puesto;
        System::Windows::Forms::ComboBox^ cmb_puesto;
        System::Windows::Forms::Label^ lbl_fecha_inicio;
        System::Windows::Forms::DateTimePicker^ dtp_fecha_inicio;
        System::Windows::Forms::Label^ lbl_fecha_ingreso;
        System::Windows::Forms::TextBox^ txt_fecha_ingreso;
        System::Windows::Forms::Button^ btn_guardar;
        System::Windows::Forms::Button^ btn_actualizar;
        System::Windows::Forms::Button^ btn_limpiar;
        System::Windows::Forms::Button^ btn_eliminar;
        System::Windows::Forms::DataGridView^ datos_empleado;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panel_directorio = (gcnew System::Windows::Forms::Panel());
            this->datos_empleado = (gcnew System::Windows::Forms::DataGridView());
            this->lbl_titulo_dir = (gcnew System::Windows::Forms::Label());
            this->txt_buscar = (gcnew System::Windows::Forms::TextBox());
            this->lbl_col_header = (gcnew System::Windows::Forms::Label());
            this->panel_ficha = (gcnew System::Windows::Forms::Panel());
            this->lbl_titulo_ficha = (gcnew System::Windows::Forms::Label());
            this->lbl_cui = (gcnew System::Windows::Forms::Label());
            this->txt_cui = (gcnew System::Windows::Forms::TextBox());
            this->lbl_genero = (gcnew System::Windows::Forms::Label());
            this->rb_masculino = (gcnew System::Windows::Forms::RadioButton());
            this->rb_femenino = (gcnew System::Windows::Forms::RadioButton());
            this->lbl_nombres = (gcnew System::Windows::Forms::Label());
            this->txt_nombres = (gcnew System::Windows::Forms::TextBox());
            this->lbl_apellidos = (gcnew System::Windows::Forms::Label());
            this->txt_apellidos = (gcnew System::Windows::Forms::TextBox());
            this->lbl_fecha_nac = (gcnew System::Windows::Forms::Label());
            this->dtp_fecha_nac = (gcnew System::Windows::Forms::DateTimePicker());
            this->lbl_telefono = (gcnew System::Windows::Forms::Label());
            this->txt_telefono = (gcnew System::Windows::Forms::TextBox());
            this->lbl_direccion = (gcnew System::Windows::Forms::Label());
            this->txt_direccion = (gcnew System::Windows::Forms::TextBox());
            this->lbl_puesto = (gcnew System::Windows::Forms::Label());
            this->cmb_puesto = (gcnew System::Windows::Forms::ComboBox());
            this->lbl_fecha_inicio = (gcnew System::Windows::Forms::Label());
            this->dtp_fecha_inicio = (gcnew System::Windows::Forms::DateTimePicker());
            this->lbl_fecha_ingreso = (gcnew System::Windows::Forms::Label());
            this->txt_fecha_ingreso = (gcnew System::Windows::Forms::TextBox());
            this->btn_guardar = (gcnew System::Windows::Forms::Button());
            this->btn_actualizar = (gcnew System::Windows::Forms::Button());
            this->btn_limpiar = (gcnew System::Windows::Forms::Button());
            this->btn_eliminar = (gcnew System::Windows::Forms::Button());
            this->panel_directorio->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_empleado))->BeginInit();
            this->panel_ficha->SuspendLayout();
            this->SuspendLayout();
            // 
            // panel_directorio
            // 
            this->panel_directorio->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)));
            this->panel_directorio->Controls->Add(this->datos_empleado);
            this->panel_directorio->Controls->Add(this->lbl_titulo_dir);
            this->panel_directorio->Controls->Add(this->txt_buscar);
            this->panel_directorio->Controls->Add(this->lbl_col_header);
            this->panel_directorio->Location = System::Drawing::Point(0, 0);
            this->panel_directorio->Name = L"panel_directorio";
            this->panel_directorio->Size = System::Drawing::Size(290, 560);
            this->panel_directorio->TabIndex = 0;
            this->panel_directorio->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &empleado::panel_directorio_Paint);
            // 
            // datos_empleado
            // 
            this->datos_empleado->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->datos_empleado->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->datos_empleado->Location = System::Drawing::Point(3, 99);
            this->datos_empleado->Name = L"datos_empleado";
            this->datos_empleado->Size = System::Drawing::Size(284, 458);
            this->datos_empleado->TabIndex = 4;
            this->datos_empleado->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &empleado::datos_empleado_CellClick);
            this->datos_empleado->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &empleado::datos_empleado_CellContentClick);
            // 
            // lbl_titulo_dir
            // 
            this->lbl_titulo_dir->AutoSize = true;
            this->lbl_titulo_dir->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->lbl_titulo_dir->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->lbl_titulo_dir->Location = System::Drawing::Point(12, 14);
            this->lbl_titulo_dir->Name = L"lbl_titulo_dir";
            this->lbl_titulo_dir->Size = System::Drawing::Size(201, 20);
            this->lbl_titulo_dir->TabIndex = 0;
            this->lbl_titulo_dir->Text = L"DIRECTORIO DE PERSONAL";
            // 
            // txt_buscar
            // 
            this->txt_buscar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_buscar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_buscar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_buscar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(104)),
                static_cast<System::Int32>(static_cast<System::Byte>(130)));
            this->txt_buscar->Location = System::Drawing::Point(12, 44);
            this->txt_buscar->Name = L"txt_buscar";
            this->txt_buscar->Size = System::Drawing::Size(266, 25);
            this->txt_buscar->TabIndex = 1;
            this->txt_buscar->Text = L"Buscar por Nombre o CUI...";
            this->txt_buscar->TextChanged += gcnew System::EventHandler(this, &empleado::txt_buscar_TextChanged);
            this->txt_buscar->GotFocus += gcnew System::EventHandler(this, &empleado::txt_buscar_GotFocus);
            this->txt_buscar->LostFocus += gcnew System::EventHandler(this, &empleado::txt_buscar_LostFocus);
            // 
            // lbl_col_header
            // 
            this->lbl_col_header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)));
            this->lbl_col_header->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7, System::Drawing::FontStyle::Bold));
            this->lbl_col_header->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(104)),
                static_cast<System::Int32>(static_cast<System::Byte>(130)));
            this->lbl_col_header->Location = System::Drawing::Point(0, 78);
            this->lbl_col_header->Name = L"lbl_col_header";
            this->lbl_col_header->Size = System::Drawing::Size(290, 18);
            this->lbl_col_header->TabIndex = 2;
            this->lbl_col_header->Text = L"  NOMBRE                PUESTO        TEL.";
            // 
            // panel_ficha
            // 
            this->panel_ficha->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->panel_ficha->Controls->Add(this->lbl_titulo_ficha);
            this->panel_ficha->Controls->Add(this->lbl_cui);
            this->panel_ficha->Controls->Add(this->txt_cui);
            this->panel_ficha->Controls->Add(this->lbl_genero);
            this->panel_ficha->Controls->Add(this->rb_masculino);
            this->panel_ficha->Controls->Add(this->rb_femenino);
            this->panel_ficha->Controls->Add(this->lbl_nombres);
            this->panel_ficha->Controls->Add(this->txt_nombres);
            this->panel_ficha->Controls->Add(this->lbl_apellidos);
            this->panel_ficha->Controls->Add(this->txt_apellidos);
            this->panel_ficha->Controls->Add(this->lbl_fecha_nac);
            this->panel_ficha->Controls->Add(this->dtp_fecha_nac);
            this->panel_ficha->Controls->Add(this->lbl_telefono);
            this->panel_ficha->Controls->Add(this->txt_telefono);
            this->panel_ficha->Controls->Add(this->lbl_direccion);
            this->panel_ficha->Controls->Add(this->txt_direccion);
            this->panel_ficha->Controls->Add(this->lbl_puesto);
            this->panel_ficha->Controls->Add(this->cmb_puesto);
            this->panel_ficha->Controls->Add(this->lbl_fecha_inicio);
            this->panel_ficha->Controls->Add(this->dtp_fecha_inicio);
            this->panel_ficha->Controls->Add(this->lbl_fecha_ingreso);
            this->panel_ficha->Controls->Add(this->txt_fecha_ingreso);
            this->panel_ficha->Controls->Add(this->btn_guardar);
            this->panel_ficha->Controls->Add(this->btn_actualizar);
            this->panel_ficha->Controls->Add(this->btn_limpiar);
            this->panel_ficha->Controls->Add(this->btn_eliminar);
            this->panel_ficha->Location = System::Drawing::Point(290, 0);
            this->panel_ficha->Name = L"panel_ficha";
            this->panel_ficha->Size = System::Drawing::Size(440, 560);
            this->panel_ficha->TabIndex = 1;
            this->panel_ficha->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &empleado::panel_ficha_Paint);
            // 
            // lbl_titulo_ficha
            // 
            this->lbl_titulo_ficha->AutoSize = true;
            this->lbl_titulo_ficha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->lbl_titulo_ficha->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->lbl_titulo_ficha->Location = System::Drawing::Point(18, 14);
            this->lbl_titulo_ficha->Name = L"lbl_titulo_ficha";
            this->lbl_titulo_ficha->Size = System::Drawing::Size(168, 20);
            this->lbl_titulo_ficha->TabIndex = 0;
            this->lbl_titulo_ficha->Text = L"FICHA DEL EMPLEADO";
            // 
            // lbl_cui
            // 
            this->lbl_cui->AutoSize = true;
            this->lbl_cui->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_cui->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_cui->Location = System::Drawing::Point(18, 50);
            this->lbl_cui->Name = L"lbl_cui";
            this->lbl_cui->Size = System::Drawing::Size(54, 13);
            this->lbl_cui->TabIndex = 1;
            this->lbl_cui->Text = L"CUI / DPI";
            // 
            // txt_cui
            // 
            this->txt_cui->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_cui->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_cui->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_cui->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->txt_cui->Location = System::Drawing::Point(18, 66);
            this->txt_cui->MaxLength = 15;
            this->txt_cui->Name = L"txt_cui";
            this->txt_cui->Size = System::Drawing::Size(195, 25);
            this->txt_cui->TabIndex = 2;
            // 
            // lbl_genero
            // 
            this->lbl_genero->AutoSize = true;
            this->lbl_genero->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_genero->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_genero->Location = System::Drawing::Point(225, 50);
            this->lbl_genero->Name = L"lbl_genero";
            this->lbl_genero->Size = System::Drawing::Size(51, 13);
            this->lbl_genero->TabIndex = 3;
            this->lbl_genero->Text = L"GÉNERO";
            // 
            // rb_masculino
            // 
            this->rb_masculino->AutoSize = true;
            this->rb_masculino->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->rb_masculino->Checked = true;
            this->rb_masculino->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->rb_masculino->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->rb_masculino->Location = System::Drawing::Point(225, 68);
            this->rb_masculino->Name = L"rb_masculino";
            this->rb_masculino->Size = System::Drawing::Size(80, 19);
            this->rb_masculino->TabIndex = 4;
            this->rb_masculino->TabStop = true;
            this->rb_masculino->Text = L"Masculino";
            this->rb_masculino->UseVisualStyleBackColor = false;
            // 
            // rb_femenino
            // 
            this->rb_femenino->AutoSize = true;
            this->rb_femenino->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->rb_femenino->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->rb_femenino->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->rb_femenino->Location = System::Drawing::Point(315, 68);
            this->rb_femenino->Name = L"rb_femenino";
            this->rb_femenino->Size = System::Drawing::Size(78, 19);
            this->rb_femenino->TabIndex = 5;
            this->rb_femenino->Text = L"Femenino";
            this->rb_femenino->UseVisualStyleBackColor = false;
            // 
            // lbl_nombres
            // 
            this->lbl_nombres->AutoSize = true;
            this->lbl_nombres->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_nombres->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_nombres->Location = System::Drawing::Point(18, 108);
            this->lbl_nombres->Name = L"lbl_nombres";
            this->lbl_nombres->Size = System::Drawing::Size(61, 13);
            this->lbl_nombres->TabIndex = 6;
            this->lbl_nombres->Text = L"NOMBRES";
            // 
            // txt_nombres
            // 
            this->txt_nombres->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_nombres->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_nombres->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_nombres->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->txt_nombres->Location = System::Drawing::Point(18, 124);
            this->txt_nombres->MaxLength = 60;
            this->txt_nombres->Name = L"txt_nombres";
            this->txt_nombres->Size = System::Drawing::Size(195, 25);
            this->txt_nombres->TabIndex = 7;
            // 
            // lbl_apellidos
            // 
            this->lbl_apellidos->AutoSize = true;
            this->lbl_apellidos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_apellidos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_apellidos->Location = System::Drawing::Point(225, 108);
            this->lbl_apellidos->Name = L"lbl_apellidos";
            this->lbl_apellidos->Size = System::Drawing::Size(65, 13);
            this->lbl_apellidos->TabIndex = 8;
            this->lbl_apellidos->Text = L"APELLIDOS";
            // 
            // txt_apellidos
            // 
            this->txt_apellidos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_apellidos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_apellidos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_apellidos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->txt_apellidos->Location = System::Drawing::Point(225, 124);
            this->txt_apellidos->MaxLength = 60;
            this->txt_apellidos->Name = L"txt_apellidos";
            this->txt_apellidos->Size = System::Drawing::Size(195, 25);
            this->txt_apellidos->TabIndex = 9;
            // 
            // lbl_fecha_nac
            // 
            this->lbl_fecha_nac->AutoSize = true;
            this->lbl_fecha_nac->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_fecha_nac->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_fecha_nac->Location = System::Drawing::Point(18, 165);
            this->lbl_fecha_nac->Name = L"lbl_fecha_nac";
            this->lbl_fecha_nac->Size = System::Drawing::Size(115, 13);
            this->lbl_fecha_nac->TabIndex = 10;
            this->lbl_fecha_nac->Text = L"FECHA NACIMIENTO";
            // 
            // dtp_fecha_nac
            // 
            this->dtp_fecha_nac->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dtp_fecha_nac->Location = System::Drawing::Point(18, 181);
            this->dtp_fecha_nac->Name = L"dtp_fecha_nac";
            this->dtp_fecha_nac->Size = System::Drawing::Size(180, 20);
            this->dtp_fecha_nac->TabIndex = 11;
            // 
            // lbl_telefono
            // 
            this->lbl_telefono->AutoSize = true;
            this->lbl_telefono->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_telefono->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_telefono->Location = System::Drawing::Point(210, 165);
            this->lbl_telefono->Name = L"lbl_telefono";
            this->lbl_telefono->Size = System::Drawing::Size(62, 13);
            this->lbl_telefono->TabIndex = 12;
            this->lbl_telefono->Text = L"TELÉFONO";
            // 
            // txt_telefono
            // 
            this->txt_telefono->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_telefono->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_telefono->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_telefono->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->txt_telefono->Location = System::Drawing::Point(210, 181);
            this->txt_telefono->MaxLength = 25;
            this->txt_telefono->Name = L"txt_telefono";
            this->txt_telefono->Size = System::Drawing::Size(210, 25);
            this->txt_telefono->TabIndex = 13;
            // 
            // lbl_direccion
            // 
            this->lbl_direccion->AutoSize = true;
            this->lbl_direccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_direccion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_direccion->Location = System::Drawing::Point(18, 220);
            this->lbl_direccion->Name = L"lbl_direccion";
            this->lbl_direccion->Size = System::Drawing::Size(65, 13);
            this->lbl_direccion->TabIndex = 14;
            this->lbl_direccion->Text = L"DIRECCIÓN";
            // 
            // txt_direccion
            // 
            this->txt_direccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_direccion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_direccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_direccion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->txt_direccion->Location = System::Drawing::Point(18, 236);
            this->txt_direccion->MaxLength = 80;
            this->txt_direccion->Name = L"txt_direccion";
            this->txt_direccion->Size = System::Drawing::Size(405, 25);
            this->txt_direccion->TabIndex = 15;
            // 
            // lbl_puesto
            // 
            this->lbl_puesto->AutoSize = true;
            this->lbl_puesto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_puesto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(144)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_puesto->Location = System::Drawing::Point(18, 278);
            this->lbl_puesto->Name = L"lbl_puesto";
            this->lbl_puesto->Size = System::Drawing::Size(48, 13);
            this->lbl_puesto->TabIndex = 16;
            this->lbl_puesto->Text = L"PUESTO";
            // 
            // cmb_puesto
            // 
            this->cmb_puesto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->cmb_puesto->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmb_puesto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->cmb_puesto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->cmb_puesto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->cmb_puesto->Location = System::Drawing::Point(18, 294);
            this->cmb_puesto->Name = L"cmb_puesto";
            this->cmb_puesto->Size = System::Drawing::Size(195, 25);
            this->cmb_puesto->TabIndex = 17;
            // 
            // lbl_fecha_inicio
            // 
            this->lbl_fecha_inicio->AutoSize = true;
            this->lbl_fecha_inicio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_fecha_inicio->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_fecha_inicio->Location = System::Drawing::Point(225, 278);
            this->lbl_fecha_inicio->Name = L"lbl_fecha_inicio";
            this->lbl_fecha_inicio->Size = System::Drawing::Size(129, 13);
            this->lbl_fecha_inicio->TabIndex = 18;
            this->lbl_fecha_inicio->Text = L"FECHA CONTRATACIÓN";
            // 
            // dtp_fecha_inicio
            // 
            this->dtp_fecha_inicio->Format = System::Windows::Forms::DateTimePickerFormat::Short;
            this->dtp_fecha_inicio->Location = System::Drawing::Point(225, 294);
            this->dtp_fecha_inicio->Name = L"dtp_fecha_inicio";
            this->dtp_fecha_inicio->Size = System::Drawing::Size(198, 20);
            this->dtp_fecha_inicio->TabIndex = 19;
            // 
            // lbl_fecha_ingreso
            // 
            this->lbl_fecha_ingreso->AutoSize = true;
            this->lbl_fecha_ingreso->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_fecha_ingreso->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(144)), static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lbl_fecha_ingreso->Location = System::Drawing::Point(18, 335);
            this->lbl_fecha_ingreso->Name = L"lbl_fecha_ingreso";
            this->lbl_fecha_ingreso->Size = System::Drawing::Size(158, 13);
            this->lbl_fecha_ingreso->TabIndex = 20;
            this->lbl_fecha_ingreso->Text = L"FECHA INGRESO AL SISTEMA";
            // 
            // txt_fecha_ingreso
            // 
            this->txt_fecha_ingreso->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
            this->txt_fecha_ingreso->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->txt_fecha_ingreso->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_fecha_ingreso->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)),
                static_cast<System::Int32>(static_cast<System::Byte>(104)), static_cast<System::Int32>(static_cast<System::Byte>(130)));
            this->txt_fecha_ingreso->Location = System::Drawing::Point(18, 351);
            this->txt_fecha_ingreso->Name = L"txt_fecha_ingreso";
            this->txt_fecha_ingreso->ReadOnly = true;
            this->txt_fecha_ingreso->Size = System::Drawing::Size(405, 25);
            this->txt_fecha_ingreso->TabIndex = 21;
            // 
            // btn_guardar
            // 
            this->btn_guardar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(127)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_guardar->FlatAppearance->BorderSize = 0;
            this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_guardar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_guardar->ForeColor = System::Drawing::Color::White;
            this->btn_guardar->Location = System::Drawing::Point(18, 400);
            this->btn_guardar->Name = L"btn_guardar";
            this->btn_guardar->Size = System::Drawing::Size(195, 36);
            this->btn_guardar->TabIndex = 22;
            this->btn_guardar->Text = L"Guardar";
            this->btn_guardar->UseVisualStyleBackColor = false;
            this->btn_guardar->Click += gcnew System::EventHandler(this, &empleado::btn_guardar_Click);
            // 
            // btn_actualizar
            // 
            this->btn_actualizar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(200)),
                static_cast<System::Int32>(static_cast<System::Byte>(150)));
            this->btn_actualizar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_actualizar->FlatAppearance->BorderSize = 0;
            this->btn_actualizar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_actualizar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_actualizar->ForeColor = System::Drawing::Color::White;
            this->btn_actualizar->Location = System::Drawing::Point(225, 400);
            this->btn_actualizar->Name = L"btn_actualizar";
            this->btn_actualizar->Size = System::Drawing::Size(198, 36);
            this->btn_actualizar->TabIndex = 23;
            this->btn_actualizar->Text = L"Actualizar";
            this->btn_actualizar->UseVisualStyleBackColor = false;
            this->btn_actualizar->Click += gcnew System::EventHandler(this, &empleado::btn_actualizar_Click);
            // 
            // btn_limpiar
            // 
            this->btn_limpiar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(42)), static_cast<System::Int32>(static_cast<System::Byte>(47)),
                static_cast<System::Int32>(static_cast<System::Byte>(62)));
            this->btn_limpiar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_limpiar->FlatAppearance->BorderSize = 0;
            this->btn_limpiar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_limpiar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_limpiar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(212)),
                static_cast<System::Int32>(static_cast<System::Byte>(232)));
            this->btn_limpiar->Location = System::Drawing::Point(18, 444);
            this->btn_limpiar->Name = L"btn_limpiar";
            this->btn_limpiar->Size = System::Drawing::Size(195, 36);
            this->btn_limpiar->TabIndex = 24;
            this->btn_limpiar->Text = L"Limpiar";
            this->btn_limpiar->UseVisualStyleBackColor = false;
            this->btn_limpiar->Click += gcnew System::EventHandler(this, &empleado::btn_limpiar_Click);
            // 
            // btn_eliminar
            // 
            this->btn_eliminar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
                static_cast<System::Int32>(static_cast<System::Byte>(68)));
            this->btn_eliminar->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_eliminar->FlatAppearance->BorderSize = 0;
            this->btn_eliminar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_eliminar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_eliminar->ForeColor = System::Drawing::Color::White;
            this->btn_eliminar->Location = System::Drawing::Point(225, 444);
            this->btn_eliminar->Name = L"btn_eliminar";
            this->btn_eliminar->Size = System::Drawing::Size(198, 36);
            this->btn_eliminar->TabIndex = 25;
            this->btn_eliminar->Text = L"Eliminar";
            this->btn_eliminar->UseVisualStyleBackColor = false;
            this->btn_eliminar->Click += gcnew System::EventHandler(this, &empleado::btn_eliminar_Click);
            // 
            // empleado
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
                static_cast<System::Int32>(static_cast<System::Byte>(20)));
            this->ClientSize = System::Drawing::Size(730, 560);
            this->Controls->Add(this->panel_directorio);
            this->Controls->Add(this->panel_ficha);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"empleado";
            this->Text = L"Gestión de Empleados";
            this->panel_directorio->ResumeLayout(false);
            this->panel_directorio->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_empleado))->EndInit();
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
            datos_empleado->ColumnCount = 5;
            datos_empleado->Columns[0]->Name = L"ID";
            datos_empleado->Columns[1]->Name = L"Nombres";
            datos_empleado->Columns[2]->Name = L"Apellidos";
            datos_empleado->Columns[3]->Name = L"Puesto";
            datos_empleado->Columns[4]->Name = L"Tel\u00E9fono";
            datos_empleado->Columns[0]->Width = 30;
            datos_empleado->Columns[1]->Width = 80;
            datos_empleado->Columns[2]->Width = 80;
            datos_empleado->Columns[3]->Width = 55;
            datos_empleado->Columns[4]->Width = 65;
            datos_empleado->AllowUserToAddRows = false;
            datos_empleado->RowHeadersVisible = false;
            datos_empleado->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            datos_empleado->EnableHeadersVisualStyles = false;
            datos_empleado->ReadOnly = true;
            datos_empleado->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 30, 45);
            datos_empleado->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
            datos_empleado->ColumnHeadersDefaultCellStyle->Font =
                (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            datos_empleado->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(35, 35, 48);
            datos_empleado->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
            datos_empleado->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(26, 127, 232);
            datos_empleado->AlternatingRowsDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(40, 40, 55);
            datos_empleado->AlternatingRowsDefaultCellStyle->ForeColor = System::Drawing::Color::White;
        }

        void CargarPuestosDB() {
            cmb_puesto->Items->Clear();
            cmb_puesto->Items->Add(L"-- Seleccionar --");
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand("SELECT puesto FROM puestos ORDER BY puesto", con);
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                while (dr->Read())
                    cmb_puesto->Items->Add(dr["puesto"]->ToString());
                dr->Close();
                con->Close();
            }
            catch (Exception^) {
                cmb_puesto->Items->Add(L"Cajero");
                cmb_puesto->Items->Add(L"Supervisor");
                cmb_puesto->Items->Add(L"Gerente");
                cmb_puesto->Items->Add(L"Bodeguero");
                cmb_puesto->Items->Add(L"Administrador");
            }
            cmb_puesto->SelectedIndex = 0;
        }

        int ObtenerIdPuesto(String^ nombre) {
            int id = 0;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT id_puesto FROM puestos WHERE puesto=@p LIMIT 1", con);
                cmd->Parameters->AddWithValue("@p", nombre);
                con->Open();
                Object^ res = cmd->ExecuteScalar();
                if (res != nullptr) id = Convert::ToInt32(res);
                con->Close();
            }
            catch (...) {}
            return id;
        }

        void CargarEmpleados(String^ filtro) {
            datos_empleado->Rows->Clear();
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "SELECT e.id_empleado, e.nombres, e.apellidos, p.puesto, e.telefono "
                    "FROM empleados e LEFT JOIN puestos p ON e.id_puesto=p.id_puesto "
                    "WHERE e.nombres LIKE @f OR e.apellidos LIKE @f OR e.cui LIKE @f "
                    "ORDER BY e.nombres";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@f", "%" + filtro + "%");
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                while (dr->Read()) {
                    String^ t_puesto = dr->IsDBNull(dr->GetOrdinal("puesto")) ? "Sin Puesto" : dr->GetString("puesto");
                    String^ t_telefono = dr->IsDBNull(dr->GetOrdinal("telefono")) ? "" : dr->GetString("telefono");
                    datos_empleado->Rows->Add(
                        dr["id_empleado"]->ToString(),
                        dr["nombres"]->ToString(),
                        dr["apellidos"]->ToString(),
                        t_puesto, t_telefono);
                }
                dr->Close();
                con->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar empleados:\n" + ex->Message);
            }
        }

        void CargarEmpleados() { CargarEmpleados(L""); }

        void LimpiarFormulario() {
            txt_cui->Text = L"";
            txt_nombres->Text = L"";
            txt_apellidos->Text = L"";
            txt_telefono->Text = L"";
            txt_direccion->Text = L"";
            rb_masculino->Checked = true;
            dtp_fecha_nac->Value = System::DateTime::Now;
            dtp_fecha_inicio->Value = System::DateTime::Now;
            txt_fecha_ingreso->Text = System::DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
            cmb_puesto->SelectedIndex = 0;
            id_empleado_sel = -1;
        }

        // ============================================================
        //  EVENTOS
        // ============================================================
        System::Void txt_buscar_GotFocus(System::Object^ sender, System::EventArgs^ e) {
            if (txt_buscar->Text == L"Buscar por Nombre o CUI...") {
                txt_buscar->Text = L"";
                txt_buscar->ForeColor = System::Drawing::Color::FromArgb(200, 212, 232);
            }
        }
        System::Void txt_buscar_LostFocus(System::Object^ sender, System::EventArgs^ e) {
            if (txt_buscar->Text->Trim() == L"") {
                txt_buscar->ForeColor = System::Drawing::Color::FromArgb(90, 104, 130);
                txt_buscar->Text = L"Buscar por Nombre o CUI...";
            }
        }
        System::Void txt_buscar_TextChanged(System::Object^ sender, System::EventArgs^ e) {
            if (txt_buscar->Text != L"Buscar por Nombre o CUI...")
                CargarEmpleados(txt_buscar->Text->Trim());
        }

        System::Void datos_empleado_CellClick(System::Object^ sender,
            System::Windows::Forms::DataGridViewCellEventArgs^ e) {
            if (e->RowIndex < 0) return;
            int id = Convert::ToInt32(datos_empleado->Rows[e->RowIndex]->Cells[0]->Value);
            id_empleado_sel = id;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "SELECT e.*, p.puesto FROM empleados e "
                    "LEFT JOIN puestos p ON e.id_puesto=p.id_puesto "
                    "WHERE e.id_empleado=@id", con);
                cmd->Parameters->AddWithValue("@id", id);
                con->Open();
                MySqlDataReader^ dr = cmd->ExecuteReader();
                if (dr->Read()) {
                    txt_cui->Text = dr->IsDBNull(dr->GetOrdinal("cui")) ? "" : dr->GetString("cui");
                    txt_nombres->Text = dr->IsDBNull(dr->GetOrdinal("nombres")) ? "" : dr->GetString("nombres");
                    txt_apellidos->Text = dr->IsDBNull(dr->GetOrdinal("apellidos")) ? "" : dr->GetString("apellidos");
                    txt_telefono->Text = dr->IsDBNull(dr->GetOrdinal("telefono")) ? "" : dr->GetString("telefono");
                    txt_direccion->Text = dr->IsDBNull(dr->GetOrdinal("direccion")) ? "" : dr->GetString("direccion");
                    if (!dr->IsDBNull(dr->GetOrdinal("fecha_nacimiento")))
                        dtp_fecha_nac->Value = dr->GetDateTime("fecha_nacimiento");
                    if (!dr->IsDBNull(dr->GetOrdinal("fecha_inicio_labores")))
                        dtp_fecha_inicio->Value = dr->GetDateTime("fecha_inicio_labores");
                    if (!dr->IsDBNull(dr->GetOrdinal("fecha_ingreso")))
                        txt_fecha_ingreso->Text = dr->GetDateTime("fecha_ingreso").ToString("yyyy-MM-dd HH:mm:ss");
                    if (!dr->IsDBNull(dr->GetOrdinal("genero"))) {
                        bool esMasc = dr->GetBoolean("genero");
                        rb_masculino->Checked = esMasc;
                        rb_femenino->Checked = !esMasc;
                    }
                    String^ puesto = dr->IsDBNull(dr->GetOrdinal("puesto")) ? "" : dr->GetString("puesto");
                    int idx = cmb_puesto->Items->IndexOf(puesto);
                    cmb_puesto->SelectedIndex = (idx >= 0) ? idx : 0;
                }
                dr->Close();
                con->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al cargar detalles:\n" + ex->Message);
            }
        }

        System::Void btn_guardar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (txt_cui->Text->Trim() == L"" || txt_nombres->Text->Trim() == L"") {
                MessageBox::Show(L"CUI y Nombres son campos requeridos.",
                    L"Validaci\u00F3n", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            int  id_puesto = (cmb_puesto->SelectedIndex > 0)
                ? ObtenerIdPuesto(cmb_puesto->SelectedItem->ToString()) : 0;
            bool genero = rb_masculino->Checked;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "INSERT INTO empleados "
                    "(nombres,apellidos,direccion,telefono,cui,genero,"
                    " fecha_nacimiento,id_puesto,fecha_inicio_labores,fecha_ingreso) "
                    "VALUES(@n,@a,@dir,@tel,@cui,@gen,@fnac,@pue,@fini,NOW())";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@n", txt_nombres->Text->Trim());
                cmd->Parameters->AddWithValue("@a", txt_apellidos->Text->Trim());
                cmd->Parameters->AddWithValue("@dir", txt_direccion->Text->Trim());
                cmd->Parameters->AddWithValue("@tel", txt_telefono->Text->Trim());
                cmd->Parameters->AddWithValue("@cui", txt_cui->Text->Trim());
                cmd->Parameters->AddWithValue("@gen", genero ? 1 : 0);
                cmd->Parameters->AddWithValue("@fnac", dtp_fecha_nac->Value.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@pue", id_puesto);
                cmd->Parameters->AddWithValue("@fini", dtp_fecha_inicio->Value.ToString("yyyy-MM-dd"));
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Empleado guardado correctamente.",
                    L"Guardar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LimpiarFormulario();
                CargarEmpleados();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al guardar:\n" + ex->Message);
            }
        }

        System::Void btn_actualizar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (id_empleado_sel < 0) {
                MessageBox::Show(L"Selecciona un empleado de la lista.",
                    L"Actualizar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            int  id_puesto = (cmb_puesto->SelectedIndex > 0)
                ? ObtenerIdPuesto(cmb_puesto->SelectedItem->ToString()) : 0;
            bool genero = rb_masculino->Checked;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                String^ sql =
                    "UPDATE empleados SET "
                    "nombres=@n, apellidos=@a, direccion=@dir, telefono=@tel, "
                    "cui=@cui, genero=@gen, fecha_nacimiento=@fnac, "
                    "id_puesto=@pue, fecha_inicio_labores=@fini "
                    "WHERE id_empleado=@id";
                MySqlCommand^ cmd = gcnew MySqlCommand(sql, con);
                cmd->Parameters->AddWithValue("@n", txt_nombres->Text->Trim());
                cmd->Parameters->AddWithValue("@a", txt_apellidos->Text->Trim());
                cmd->Parameters->AddWithValue("@dir", txt_direccion->Text->Trim());
                cmd->Parameters->AddWithValue("@tel", txt_telefono->Text->Trim());
                cmd->Parameters->AddWithValue("@cui", txt_cui->Text->Trim());
                cmd->Parameters->AddWithValue("@gen", genero ? 1 : 0);
                cmd->Parameters->AddWithValue("@fnac", dtp_fecha_nac->Value.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@pue", id_puesto);
                cmd->Parameters->AddWithValue("@fini", dtp_fecha_inicio->Value.ToString("yyyy-MM-dd"));
                cmd->Parameters->AddWithValue("@id", id_empleado_sel);
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Empleado actualizado.",
                    L"Actualizar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LimpiarFormulario();
                CargarEmpleados();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al actualizar:\n" + ex->Message);
            }
        }

        System::Void btn_limpiar_Click(System::Object^ sender, System::EventArgs^ e) { LimpiarFormulario(); }

        System::Void btn_eliminar_Click(System::Object^ sender, System::EventArgs^ e) {
            if (id_empleado_sel < 0) {
                MessageBox::Show(L"Selecciona un empleado de la lista.",
                    L"Eliminar", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            System::Windows::Forms::DialogResult res = MessageBox::Show(
                L"\u00BFDeseas eliminar este empleado del sistema?", L"Confirmar",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question);
            if (res != System::Windows::Forms::DialogResult::Yes) return;
            try {
                MySqlConnection^ con = gcnew MySqlConnection(connectionString);
                MySqlCommand^ cmd = gcnew MySqlCommand(
                    "DELETE FROM empleados WHERE id_empleado=@id", con);
                cmd->Parameters->AddWithValue("@id", id_empleado_sel);
                con->Open();
                cmd->ExecuteNonQuery();
                con->Close();
                MessageBox::Show(L"Empleado eliminado.",
                    L"Eliminar", MessageBoxButtons::OK, MessageBoxIcon::Information);
                LimpiarFormulario();
                CargarEmpleados();
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al eliminar:\n" + ex->Message);
            }
        }

        System::Void panel_ficha_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
        System::Void panel_directorio_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
    private: System::Void datos_empleado_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
    }
};
}