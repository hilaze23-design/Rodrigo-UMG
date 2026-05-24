#pragma once
namespace CppCLRWinFormsProject {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class factura : public System::Windows::Forms::Form
	{
	private:
		String^ connectionString = "server=localhost;port=3306;database=facturas;uid=root;password=12345;";

	private: System::Windows::Forms::DataGridView^ datos_factura;
		   double totalFactura = 0.0;
		   bool clienteExistente = false;

	public:
		factura(void)
		{
			InitializeComponent();
			ConfigurarTabla();
			dtp_fecha_fac->Value = System::DateTime::Now;
		}

	protected:
		~factura() { if (components) delete components; }

	private:
		System::Windows::Forms::Panel^ panel_productos;
		System::Windows::Forms::Panel^ panel_fiscal;
		System::Windows::Forms::Label^ lbl_sec_productos;
		System::Windows::Forms::Label^ lbl_codigo;
		System::Windows::Forms::TextBox^ txt_codigo;
		System::Windows::Forms::Label^ lbl_cantidad;
		System::Windows::Forms::TextBox^ txt_cantidad;
		System::Windows::Forms::Button^ btn_agregar;
		System::Windows::Forms::Label^ lbl_sec_comprobante;
		System::Windows::Forms::Label^ lbl_serie;
		System::Windows::Forms::TextBox^ txt_serie;
		System::Windows::Forms::Label^ lbl_no_factura;
		System::Windows::Forms::TextBox^ txt_no_factura;
		System::Windows::Forms::Label^ lbl_id_venta;
		System::Windows::Forms::TextBox^ txt_id_venta;
		System::Windows::Forms::Label^ lbl_fecha_fac;
		System::Windows::Forms::DateTimePicker^ dtp_fecha_fac;
		System::Windows::Forms::Label^ lbl_id_empleado;
		System::Windows::Forms::TextBox^ txt_id_empleado;
		System::Windows::Forms::Label^ lbl_sec_fiscal;
		System::Windows::Forms::Label^ lbl_nit;
		System::Windows::Forms::TextBox^ txt_nit;
		System::Windows::Forms::Button^ btn_buscar_nit;
		System::Windows::Forms::Label^ lbl_nombre;
		System::Windows::Forms::TextBox^ txt_nombre;
		System::Windows::Forms::Label^ lbl_direccion;
		System::Windows::Forms::TextBox^ txt_direccion;
		System::Windows::Forms::Panel^ panel_total;
		System::Windows::Forms::Label^ lbl_total_txt;
		System::Windows::Forms::Label^ lbl_total_monto;
		System::Windows::Forms::Button^ btn_emitir;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel_productos = (gcnew System::Windows::Forms::Panel());
			this->datos_factura = (gcnew System::Windows::Forms::DataGridView());
			this->btn_agregar = (gcnew System::Windows::Forms::Button());
			this->txt_cantidad = (gcnew System::Windows::Forms::TextBox());
			this->lbl_cantidad = (gcnew System::Windows::Forms::Label());
			this->txt_codigo = (gcnew System::Windows::Forms::TextBox());
			this->lbl_codigo = (gcnew System::Windows::Forms::Label());
			this->lbl_sec_productos = (gcnew System::Windows::Forms::Label());
			this->panel_fiscal = (gcnew System::Windows::Forms::Panel());
			this->lbl_sec_comprobante = (gcnew System::Windows::Forms::Label());
			this->lbl_serie = (gcnew System::Windows::Forms::Label());
			this->txt_serie = (gcnew System::Windows::Forms::TextBox());
			this->lbl_no_factura = (gcnew System::Windows::Forms::Label());
			this->txt_no_factura = (gcnew System::Windows::Forms::TextBox());
			this->lbl_id_venta = (gcnew System::Windows::Forms::Label());
			this->txt_id_venta = (gcnew System::Windows::Forms::TextBox());
			this->lbl_fecha_fac = (gcnew System::Windows::Forms::Label());
			this->dtp_fecha_fac = (gcnew System::Windows::Forms::DateTimePicker());
			this->lbl_id_empleado = (gcnew System::Windows::Forms::Label());
			this->txt_id_empleado = (gcnew System::Windows::Forms::TextBox());
			this->lbl_sec_fiscal = (gcnew System::Windows::Forms::Label());
			this->lbl_nit = (gcnew System::Windows::Forms::Label());
			this->txt_nit = (gcnew System::Windows::Forms::TextBox());
			this->btn_buscar_nit = (gcnew System::Windows::Forms::Button());
			this->lbl_nombre = (gcnew System::Windows::Forms::Label());
			this->txt_nombre = (gcnew System::Windows::Forms::TextBox());
			this->lbl_direccion = (gcnew System::Windows::Forms::Label());
			this->txt_direccion = (gcnew System::Windows::Forms::TextBox());
			this->panel_total = (gcnew System::Windows::Forms::Panel());
			this->lbl_total_monto = (gcnew System::Windows::Forms::Label());
			this->lbl_total_txt = (gcnew System::Windows::Forms::Label());
			this->btn_emitir = (gcnew System::Windows::Forms::Button());
			this->panel_productos->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_factura))->BeginInit();
			this->panel_fiscal->SuspendLayout();
			this->panel_total->SuspendLayout();
			this->SuspendLayout();

			// panel_productos
			this->panel_productos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel_productos->Controls->Add(this->datos_factura);
			this->panel_productos->Controls->Add(this->btn_agregar);
			this->panel_productos->Controls->Add(this->txt_cantidad);
			this->panel_productos->Controls->Add(this->lbl_cantidad);
			this->panel_productos->Controls->Add(this->txt_codigo);
			this->panel_productos->Controls->Add(this->lbl_codigo);
			this->panel_productos->Controls->Add(this->lbl_sec_productos);
			this->panel_productos->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_productos->Location = System::Drawing::Point(0, 0);
			this->panel_productos->Name = L"panel_productos";
			this->panel_productos->Size = System::Drawing::Size(411, 480);
			this->panel_productos->TabIndex = 0;
			this->panel_productos->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &factura::panel_productos_Paint);

			// datos_factura
			this->datos_factura->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->datos_factura->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->datos_factura->Location = System::Drawing::Point(15, 105);
			this->datos_factura->Name = L"datos_factura";
			this->datos_factura->Size = System::Drawing::Size(380, 347);
			this->datos_factura->TabIndex = 7;
			this->datos_factura->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &factura::datos_factura_CellContentClick);

			// btn_agregar
			this->btn_agregar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btn_agregar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_agregar->FlatAppearance->BorderSize = 0;
			this->btn_agregar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_agregar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btn_agregar->ForeColor = System::Drawing::Color::White;
			this->btn_agregar->Location = System::Drawing::Point(295, 67);
			this->btn_agregar->Name = L"btn_agregar";
			this->btn_agregar->Size = System::Drawing::Size(100, 26);
			this->btn_agregar->TabIndex = 1;
			this->btn_agregar->Text = L"Agregar +";
			this->btn_agregar->UseVisualStyleBackColor = false;
			this->btn_agregar->Click += gcnew System::EventHandler(this, &factura::btn_agregar_Click);

			// txt_cantidad
			this->txt_cantidad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->txt_cantidad->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_cantidad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_cantidad->ForeColor = System::Drawing::Color::White;
			this->txt_cantidad->Location = System::Drawing::Point(210, 68);
			this->txt_cantidad->Name = L"txt_cantidad";
			this->txt_cantidad->Size = System::Drawing::Size(70, 25);
			this->txt_cantidad->TabIndex = 2;
			this->txt_cantidad->Text = L"1";

			// lbl_cantidad
			this->lbl_cantidad->AutoSize = true;
			this->lbl_cantidad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_cantidad->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_cantidad->Location = System::Drawing::Point(210, 50);
			this->lbl_cantidad->Name = L"lbl_cantidad";
			this->lbl_cantidad->TabIndex = 3;
			this->lbl_cantidad->Text = L"CANTIDAD";

			// txt_codigo
			this->txt_codigo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->txt_codigo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_codigo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_codigo->ForeColor = System::Drawing::Color::White;
			this->txt_codigo->Location = System::Drawing::Point(15, 68);
			this->txt_codigo->Name = L"txt_codigo";
			this->txt_codigo->Size = System::Drawing::Size(180, 25);
			this->txt_codigo->TabIndex = 4;

			// lbl_codigo
			this->lbl_codigo->AutoSize = true;
			this->lbl_codigo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_codigo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_codigo->Location = System::Drawing::Point(15, 50);
			this->lbl_codigo->Name = L"lbl_codigo";
			this->lbl_codigo->TabIndex = 5;
			this->lbl_codigo->Text = L"C\u00D3DIGO DE PRODUCTO";

			// lbl_sec_productos
			this->lbl_sec_productos->AutoSize = true;
			this->lbl_sec_productos->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->lbl_sec_productos->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbl_sec_productos->Location = System::Drawing::Point(15, 15);
			this->lbl_sec_productos->Name = L"lbl_sec_productos";
			this->lbl_sec_productos->TabIndex = 6;
			this->lbl_sec_productos->Text = L"1. CARGA DE PRODUCTOS";

			// panel_fiscal
			this->panel_fiscal->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->panel_fiscal->Controls->Add(this->lbl_sec_comprobante);
			this->panel_fiscal->Controls->Add(this->lbl_serie);
			this->panel_fiscal->Controls->Add(this->txt_serie);
			this->panel_fiscal->Controls->Add(this->lbl_no_factura);
			this->panel_fiscal->Controls->Add(this->txt_no_factura);
			this->panel_fiscal->Controls->Add(this->lbl_id_venta);
			this->panel_fiscal->Controls->Add(this->txt_id_venta);
			this->panel_fiscal->Controls->Add(this->lbl_fecha_fac);
			this->panel_fiscal->Controls->Add(this->dtp_fecha_fac);
			this->panel_fiscal->Controls->Add(this->lbl_id_empleado);
			this->panel_fiscal->Controls->Add(this->txt_id_empleado);
			this->panel_fiscal->Controls->Add(this->lbl_sec_fiscal);
			this->panel_fiscal->Controls->Add(this->lbl_nit);
			this->panel_fiscal->Controls->Add(this->txt_nit);
			this->panel_fiscal->Controls->Add(this->btn_buscar_nit);
			this->panel_fiscal->Controls->Add(this->lbl_nombre);
			this->panel_fiscal->Controls->Add(this->txt_nombre);
			this->panel_fiscal->Controls->Add(this->lbl_direccion);
			this->panel_fiscal->Controls->Add(this->txt_direccion);
			this->panel_fiscal->Controls->Add(this->panel_total);
			this->panel_fiscal->Controls->Add(this->btn_emitir);
			this->panel_fiscal->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel_fiscal->Location = System::Drawing::Point(411, 0);
			this->panel_fiscal->Name = L"panel_fiscal";
			this->panel_fiscal->Size = System::Drawing::Size(300, 480);
			this->panel_fiscal->TabIndex = 1;

			// lbl_sec_comprobante
			this->lbl_sec_comprobante->AutoSize = true;
			this->lbl_sec_comprobante->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_sec_comprobante->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbl_sec_comprobante->Location = System::Drawing::Point(15, 12);
			this->lbl_sec_comprobante->Name = L"lbl_sec_comprobante";
			this->lbl_sec_comprobante->TabIndex = 0;
			this->lbl_sec_comprobante->Text = L"DATOS DEL COMPROBANTE";

			// lbl_serie
			this->lbl_serie->AutoSize = true;
			this->lbl_serie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_serie->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_serie->Location = System::Drawing::Point(15, 38);
			this->lbl_serie->Name = L"lbl_serie";
			this->lbl_serie->TabIndex = 1;
			this->lbl_serie->Text = L"SERIE";

			// txt_serie
			this->txt_serie->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->txt_serie->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_serie->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_serie->ForeColor = System::Drawing::Color::White;
			this->txt_serie->Location = System::Drawing::Point(15, 55);
			this->txt_serie->Name = L"txt_serie";
			this->txt_serie->Size = System::Drawing::Size(60, 25);
			this->txt_serie->TabIndex = 2;

			// lbl_no_factura
			this->lbl_no_factura->AutoSize = true;
			this->lbl_no_factura->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_no_factura->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_no_factura->Location = System::Drawing::Point(85, 38);
			this->lbl_no_factura->Name = L"lbl_no_factura";
			this->lbl_no_factura->TabIndex = 3;
			this->lbl_no_factura->Text = L"NO. FACTURA";

			// txt_no_factura
			this->txt_no_factura->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->txt_no_factura->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_no_factura->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_no_factura->ForeColor = System::Drawing::Color::White;
			this->txt_no_factura->Location = System::Drawing::Point(85, 55);
			this->txt_no_factura->Name = L"txt_no_factura";
			this->txt_no_factura->Size = System::Drawing::Size(100, 25);
			this->txt_no_factura->TabIndex = 4;

			// lbl_id_venta
			this->lbl_id_venta->AutoSize = true;
			this->lbl_id_venta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_id_venta->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_id_venta->Location = System::Drawing::Point(195, 38);
			this->lbl_id_venta->Name = L"lbl_id_venta";
			this->lbl_id_venta->TabIndex = 5;
			this->lbl_id_venta->Text = L"ID VENTA";

			// txt_id_venta
			this->txt_id_venta->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(36)));
			this->txt_id_venta->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_id_venta->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_id_venta->ForeColor = System::Drawing::Color::DarkGray;
			this->txt_id_venta->Location = System::Drawing::Point(195, 55);
			this->txt_id_venta->Name = L"txt_id_venta";
			this->txt_id_venta->ReadOnly = true;
			this->txt_id_venta->Size = System::Drawing::Size(90, 25);
			this->txt_id_venta->TabIndex = 6;
			this->txt_id_venta->Text = L"Auto";

			// lbl_fecha_fac
			this->lbl_fecha_fac->AutoSize = true;
			this->lbl_fecha_fac->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_fecha_fac->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_fecha_fac->Location = System::Drawing::Point(15, 88);
			this->lbl_fecha_fac->Name = L"lbl_fecha_fac";
			this->lbl_fecha_fac->TabIndex = 7;
			this->lbl_fecha_fac->Text = L"FECHA FACTURA";

			// dtp_fecha_fac — editable
			this->dtp_fecha_fac->Enabled = true;
			this->dtp_fecha_fac->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dtp_fecha_fac->Location = System::Drawing::Point(15, 105);
			this->dtp_fecha_fac->Name = L"dtp_fecha_fac";
			this->dtp_fecha_fac->Size = System::Drawing::Size(130, 20);
			this->dtp_fecha_fac->TabIndex = 8;

			// lbl_id_empleado
			this->lbl_id_empleado->AutoSize = true;
			this->lbl_id_empleado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_id_empleado->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_id_empleado->Location = System::Drawing::Point(155, 88);
			this->lbl_id_empleado->Name = L"lbl_id_empleado";
			this->lbl_id_empleado->TabIndex = 9;
			this->lbl_id_empleado->Text = L"ID EMPLEADO";

			// txt_id_empleado
			this->txt_id_empleado->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->txt_id_empleado->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_id_empleado->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_id_empleado->ForeColor = System::Drawing::Color::White;
			this->txt_id_empleado->Location = System::Drawing::Point(155, 105);
			this->txt_id_empleado->Name = L"txt_id_empleado";
			this->txt_id_empleado->Size = System::Drawing::Size(130, 25);
			this->txt_id_empleado->TabIndex = 10;

			// lbl_sec_fiscal
			this->lbl_sec_fiscal->AutoSize = true;
			this->lbl_sec_fiscal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->lbl_sec_fiscal->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbl_sec_fiscal->Location = System::Drawing::Point(15, 140);
			this->lbl_sec_fiscal->Name = L"lbl_sec_fiscal";
			this->lbl_sec_fiscal->TabIndex = 11;
			this->lbl_sec_fiscal->Text = L"DATOS DEL CLIENTE";

			// lbl_nit
			this->lbl_nit->AutoSize = true;
			this->lbl_nit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_nit->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_nit->Location = System::Drawing::Point(15, 166);
			this->lbl_nit->Name = L"lbl_nit";
			this->lbl_nit->TabIndex = 12;
			this->lbl_nit->Text = L"NIT DEL CLIENTE";

			// txt_nit
			this->txt_nit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->txt_nit->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_nit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_nit->ForeColor = System::Drawing::Color::White;
			this->txt_nit->Location = System::Drawing::Point(15, 183);
			this->txt_nit->Name = L"txt_nit";
			this->txt_nit->Size = System::Drawing::Size(200, 25);
			this->txt_nit->TabIndex = 13;

			// btn_buscar_nit
			this->btn_buscar_nit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
			this->btn_buscar_nit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_buscar_nit->FlatAppearance->BorderSize = 0;
			this->btn_buscar_nit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_buscar_nit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->btn_buscar_nit->ForeColor = System::Drawing::Color::White;
			this->btn_buscar_nit->Location = System::Drawing::Point(225, 182);
			this->btn_buscar_nit->Name = L"btn_buscar_nit";
			this->btn_buscar_nit->Size = System::Drawing::Size(60, 27);
			this->btn_buscar_nit->TabIndex = 14;
			this->btn_buscar_nit->Text = L"Buscar";
			this->btn_buscar_nit->UseVisualStyleBackColor = false;
			this->btn_buscar_nit->Click += gcnew System::EventHandler(this, &factura::btn_buscar_nit_Click);

			// lbl_nombre
			this->lbl_nombre->AutoSize = true;
			this->lbl_nombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_nombre->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_nombre->Location = System::Drawing::Point(15, 218);
			this->lbl_nombre->Name = L"lbl_nombre";
			this->lbl_nombre->TabIndex = 15;
			this->lbl_nombre->Text = L"NOMBRE COMPLETO";

			// txt_nombre — editable por defecto
			this->txt_nombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->txt_nombre->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_nombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_nombre->ForeColor = System::Drawing::Color::White;
			this->txt_nombre->Location = System::Drawing::Point(15, 235);
			this->txt_nombre->Name = L"txt_nombre";
			this->txt_nombre->ReadOnly = false;
			this->txt_nombre->Size = System::Drawing::Size(270, 25);
			this->txt_nombre->TabIndex = 16;

			// lbl_direccion
			this->lbl_direccion->AutoSize = true;
			this->lbl_direccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
			this->lbl_direccion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_direccion->Location = System::Drawing::Point(15, 270);
			this->lbl_direccion->Name = L"lbl_direccion";
			this->lbl_direccion->TabIndex = 17;
			this->lbl_direccion->Text = L"DIRECCI\u00D3N FISCAL";

			// txt_direccion — editable por defecto
			this->txt_direccion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->txt_direccion->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txt_direccion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txt_direccion->ForeColor = System::Drawing::Color::White;
			this->txt_direccion->Location = System::Drawing::Point(15, 287);
			this->txt_direccion->Name = L"txt_direccion";
			this->txt_direccion->ReadOnly = false;
			this->txt_direccion->Size = System::Drawing::Size(270, 25);
			this->txt_direccion->TabIndex = 18;

			// panel_total
			this->panel_total->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->panel_total->Controls->Add(this->lbl_total_monto);
			this->panel_total->Controls->Add(this->lbl_total_txt);
			this->panel_total->Location = System::Drawing::Point(15, 335);
			this->panel_total->Name = L"panel_total";
			this->panel_total->Size = System::Drawing::Size(270, 75);
			this->panel_total->TabIndex = 19;

			// lbl_total_monto
			this->lbl_total_monto->Font = (gcnew System::Drawing::Font(L"Segoe UI", 26, System::Drawing::FontStyle::Bold));
			this->lbl_total_monto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->lbl_total_monto->Location = System::Drawing::Point(12, 25);
			this->lbl_total_monto->Name = L"lbl_total_monto";
			this->lbl_total_monto->Size = System::Drawing::Size(246, 45);
			this->lbl_total_monto->TabIndex = 0;
			this->lbl_total_monto->Text = L"Q 0.00";
			this->lbl_total_monto->TextAlign = System::Drawing::ContentAlignment::MiddleRight;

			// lbl_total_txt
			this->lbl_total_txt->AutoSize = true;
			this->lbl_total_txt->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lbl_total_txt->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(150)), static_cast<System::Int32>(static_cast<System::Byte>(170)));
			this->lbl_total_txt->Location = System::Drawing::Point(12, 10);
			this->lbl_total_txt->Name = L"lbl_total_txt";
			this->lbl_total_txt->TabIndex = 1;
			this->lbl_total_txt->Text = L"TOTAL A PAGAR";

			// btn_emitir
			this->btn_emitir->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(199)), static_cast<System::Int32>(static_cast<System::Byte>(89)));
			this->btn_emitir->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_emitir->FlatAppearance->BorderSize = 0;
			this->btn_emitir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_emitir->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
			this->btn_emitir->ForeColor = System::Drawing::Color::White;
			this->btn_emitir->Location = System::Drawing::Point(15, 420);
			this->btn_emitir->Name = L"btn_emitir";
			this->btn_emitir->Size = System::Drawing::Size(270, 45);
			this->btn_emitir->TabIndex = 20;
			this->btn_emitir->Text = L"Emitir Factura";
			this->btn_emitir->UseVisualStyleBackColor = false;
			this->btn_emitir->Click += gcnew System::EventHandler(this, &factura::btn_emitir_Click);

			// factura (Form)
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 480);
			this->Controls->Add(this->panel_productos);
			this->Controls->Add(this->panel_fiscal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"factura";
			this->Text = L"Facturacion";
			this->panel_productos->ResumeLayout(false);
			this->panel_productos->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->datos_factura))->EndInit();
			this->panel_fiscal->ResumeLayout(false);
			this->panel_fiscal->PerformLayout();
			this->panel_total->ResumeLayout(false);
			this->panel_total->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

		// ================================================================
		// LOGICA
		// ================================================================

	private:
		void ConfigurarTabla() {
			datos_factura->ColumnCount = 5;
			datos_factura->Columns[0]->Name = L"Cod.";
			datos_factura->Columns[1]->Name = L"Descripcion del Producto";
			datos_factura->Columns[2]->Name = L"Precio U.";
			datos_factura->Columns[3]->Name = L"Cant.";
			datos_factura->Columns[4]->Name = L"Subtotal";
			datos_factura->Columns[0]->Width = 45;
			datos_factura->Columns[1]->Width = 145;
			datos_factura->Columns[2]->Width = 65;
			datos_factura->Columns[3]->Width = 45;
			datos_factura->Columns[4]->Width = 80;
			datos_factura->AllowUserToAddRows = false;
			datos_factura->RowHeadersVisible = false;
			datos_factura->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
			datos_factura->EnableHeadersVisualStyles = false;
			datos_factura->ReadOnly = true;
			datos_factura->ColumnHeadersDefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(30, 30, 45);
			datos_factura->ColumnHeadersDefaultCellStyle->ForeColor = System::Drawing::Color::White;
			datos_factura->DefaultCellStyle->BackColor = System::Drawing::Color::FromArgb(40, 40, 50);
			datos_factura->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
			datos_factura->DefaultCellStyle->SelectionBackColor = System::Drawing::Color::FromArgb(0, 122, 255);
		}

		System::Void btn_agregar_Click(System::Object^ sender, System::EventArgs^ e) {
			if (txt_codigo->Text->Trim() == "" || txt_cantidad->Text->Trim() == "") {
				MessageBox::Show("Ingrese el codigo del producto y la cantidad.",
					"Datos incompletos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			int cantidad = 0;
			if (!Int32::TryParse(txt_cantidad->Text->Trim(), cantidad) || cantidad <= 0) {
				MessageBox::Show("La cantidad debe ser un numero entero mayor a 0.",
					"Cantidad invalida", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			MySqlConnection^ conexion = gcnew MySqlConnection(connectionString);
			MySqlCommand^ comando = gcnew MySqlCommand(
				"SELECT id_producto, producto, precio_venta FROM productos WHERE id_producto = @id", conexion);
			comando->Parameters->AddWithValue("@id", txt_codigo->Text->Trim());
			try {
				conexion->Open();
				MySqlDataReader^ lector = comando->ExecuteReader();
				if (lector->Read()) {
					String^ codProducto = lector->GetInt32("id_producto").ToString();
					String^ descripcion = lector->GetString("producto");
					double  precio = lector->GetDouble("precio_venta");
					double  subtotal = precio * cantidad;
					bool encontrado = false;
					for each (DataGridViewRow ^ fila in datos_factura->Rows) {
						if (fila->Cells[0]->Value->ToString() == codProducto) {
							int cantExistente = Convert::ToInt32(fila->Cells[3]->Value);
							int nuevaCant = cantExistente + cantidad;
							double nuevoSub = precio * nuevaCant;
							fila->Cells[3]->Value = nuevaCant;
							fila->Cells[4]->Value = "Q " + nuevoSub.ToString("F2");
							totalFactura -= (precio * cantExistente);
							totalFactura += nuevoSub;
							encontrado = true;
							break;
						}
					}
					if (!encontrado) {
						datos_factura->Rows->Add(codProducto, descripcion,
							"Q " + precio.ToString("F2"), cantidad, "Q " + subtotal.ToString("F2"));
						totalFactura += subtotal;
					}
					lbl_total_monto->Text = "Q " + totalFactura.ToString("F2");
					txt_codigo->Clear();
					txt_cantidad->Text = "1";
					txt_codigo->Focus();
				}
				else {
					MessageBox::Show("Producto no encontrado en el sistema.",
						"Sin resultados", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error en la base de datos: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally { conexion->Close(); }
		}

		System::Void btn_buscar_nit_Click(System::Object^ sender, System::EventArgs^ e) {
			if (txt_nit->Text->Trim() == "") {
				MessageBox::Show("Por favor, ingrese un NIT valido.",
					"NIT vacio", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			MySqlConnection^ conexion = gcnew MySqlConnection(connectionString);
			MySqlCommand^ comando = gcnew MySqlCommand(
				"SELECT nombres, apellidos FROM clientes WHERE nit = @nit", conexion);
			comando->Parameters->AddWithValue("@nit", txt_nit->Text->Trim());
			try {
				conexion->Open();
				MySqlDataReader^ lector = comando->ExecuteReader();
				if (lector->Read()) {
					String^ apellidos = lector->IsDBNull(lector->GetOrdinal("apellidos"))
						? "" : lector->GetString("apellidos");
					txt_nombre->Text = lector->GetString("nombres") + " " + apellidos;
					txt_nombre->ReadOnly = true;
					txt_nombre->ForeColor = System::Drawing::Color::DarkGray;
					// direccion no existe en clientes, se deja editable para que el usuario la ingrese
					txt_direccion->ReadOnly = false;
					txt_direccion->ForeColor = System::Drawing::Color::White;
					clienteExistente = true;
				}
				else {
					MessageBox::Show(
						"NIT no registrado.\nComplete los datos manualmente.\nSe guardaran al emitir la factura.",
						"Cliente nuevo", MessageBoxButtons::OK, MessageBoxIcon::Information);
					txt_nombre->Clear();
					txt_direccion->Clear();
					txt_nombre->ReadOnly = false;
					txt_direccion->ReadOnly = false;
					txt_nombre->ForeColor = System::Drawing::Color::White;
					txt_direccion->ForeColor = System::Drawing::Color::White;
					clienteExistente = false;
					txt_nombre->Focus();
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al buscar el cliente: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally { conexion->Close(); }
		}

		System::Void btn_emitir_Click(System::Object^ sender, System::EventArgs^ e) {
			if (datos_factura->Rows->Count == 0) {
				MessageBox::Show("Agregue al menos un producto a la factura.",
					"Sin productos", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txt_serie->Text->Trim() == "") {
				MessageBox::Show("Ingrese la serie de la factura.",
					"Serie requerida", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txt_no_factura->Text->Trim() == "") {
				MessageBox::Show("Ingrese el numero de factura.",
					"Numero requerido", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txt_nit->Text->Trim() == "") {
				MessageBox::Show("Ingrese el NIT del cliente.",
					"NIT requerido", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txt_nombre->Text->Trim() == "") {
				MessageBox::Show("El nombre del cliente es obligatorio.",
					"Nombre requerido", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			if (txt_id_empleado->Text->Trim() == "") {
				MessageBox::Show("Ingrese el ID del empleado que emite la factura.",
					"Empleado requerido", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}
			int idEmpleado = 0;
			if (!Int32::TryParse(txt_id_empleado->Text->Trim(), idEmpleado)) {
				MessageBox::Show("El ID de empleado debe ser un numero entero.",
					"Dato invalido", MessageBoxButtons::OK, MessageBoxIcon::Warning); return;
			}

			MySqlConnection^ conexion = gcnew MySqlConnection(connectionString);
			try {
				conexion->Open();
				MySqlTransaction^ transaccion = conexion->BeginTransaction();

				// Paso 1: cliente nuevo -> insertar solo columnas que existen en la tabla
				int idCliente = 0;
				if (!clienteExistente) {
					array<String^>^ partes = txt_nombre->Text->Trim()->Split(' ');
					String^ nombres = partes[0];
					String^ apellidos = partes->Length > 1
						? txt_nombre->Text->Trim()->Substring(nombres->Length + 1) : "";
					// CORRECCIÓN: eliminado 'direccion' que no existe en la tabla clientes
					MySqlCommand^ cmdCli = gcnew MySqlCommand(
						"INSERT INTO clientes (nombres, apellidos, nit) "
						"VALUES (@nom, @ape, @nit); SELECT LAST_INSERT_ID();",
						conexion, transaccion);
					cmdCli->Parameters->AddWithValue("@nom", nombres);
					cmdCli->Parameters->AddWithValue("@ape", apellidos);
					cmdCli->Parameters->AddWithValue("@nit", txt_nit->Text->Trim());
					idCliente = Convert::ToInt32(cmdCli->ExecuteScalar());
				}
				else {
					MySqlCommand^ cmdGetId = gcnew MySqlCommand(
						"SELECT id_cliente FROM clientes WHERE nit = @nit",
						conexion, transaccion);
					cmdGetId->Parameters->AddWithValue("@nit", txt_nit->Text->Trim());
					idCliente = Convert::ToInt32(cmdGetId->ExecuteScalar());
				}

				// Paso 2: encabezado de venta
				MySqlCommand^ cmdVenta = gcnew MySqlCommand(
					"INSERT INTO ventas (no_factura, serie, fecha_factura, id_cliente, id_empleado) "
					"VALUES (@nof, @ser, @fec, @idc, @ide); SELECT LAST_INSERT_ID();",
					conexion, transaccion);
				cmdVenta->Parameters->AddWithValue("@nof", Convert::ToInt32(txt_no_factura->Text->Trim()));
				cmdVenta->Parameters->AddWithValue("@ser", txt_serie->Text->Trim());
				cmdVenta->Parameters->AddWithValue("@fec", dtp_fecha_fac->Value.ToString("yyyy-MM-dd"));
				cmdVenta->Parameters->AddWithValue("@idc", idCliente);
				cmdVenta->Parameters->AddWithValue("@ide", idEmpleado);
				int idVenta = Convert::ToInt32(cmdVenta->ExecuteScalar());
				txt_id_venta->Text = idVenta.ToString();

				// Paso 3: detalle y descuento de stock
				for each (DataGridViewRow ^ fila in datos_factura->Rows) {
					int    codProd = Convert::ToInt32(fila->Cells[0]->Value);
					int    cant = Convert::ToInt32(fila->Cells[3]->Value);
					String^ precioStr = fila->Cells[2]->Value->ToString()->Replace("Q ", "")->Trim();
					double precio = Convert::ToDouble(precioStr);

					MySqlCommand^ cmdDet = gcnew MySqlCommand(
						"INSERT INTO ventas_detalle (id_venta, id_producto, cantidad, precio_unitario) "
						"VALUES (@idv, @idp, @cant, @pu)",
						conexion, transaccion);
					cmdDet->Parameters->AddWithValue("@idv", idVenta);
					cmdDet->Parameters->AddWithValue("@idp", codProd);
					cmdDet->Parameters->AddWithValue("@cant", cant);
					cmdDet->Parameters->AddWithValue("@pu", precio);
					cmdDet->ExecuteNonQuery();

					MySqlCommand^ cmdStock = gcnew MySqlCommand(
						"UPDATE productos SET existencia = existencia - @cant WHERE id_producto = @idp",
						conexion, transaccion);
					cmdStock->Parameters->AddWithValue("@cant", cant);
					cmdStock->Parameters->AddWithValue("@idp", codProd);
					cmdStock->ExecuteNonQuery();
				}

				transaccion->Commit();
				GenerarFacturaTxt(idVenta);
				MessageBox::Show(
					"Factura #" + idVenta.ToString() + " emitida correctamente.\n"
					"El archivo TXT fue guardado en el Escritorio.",
					"Exito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				LimpiarFormulario();
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error al emitir la factura: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally { conexion->Close(); }
		}

		void GenerarFacturaTxt(int idVenta) {
			String^ noFactura = txt_no_factura->Text->Trim()->PadLeft(6, '0');
			String^ nombreArchivo =
				"Factura_" + txt_nombre->Text->Trim()->Replace(" ", "_") +
				"_" + noFactura + ".txt";
			String^ ruta =
				System::Environment::GetFolderPath(System::Environment::SpecialFolder::Desktop)
				+ "\\" + nombreArchivo;

			System::IO::StreamWriter^ sw =
				gcnew System::IO::StreamWriter(ruta, false, System::Text::Encoding::UTF8);
			try {
				String^ doble = "============================================================";
				String^ simple = "------------------------------------------------------------";
				sw->WriteLine(doble);
				sw->WriteLine("                   FACTURA DE VENTA");
				sw->WriteLine(doble);
				sw->WriteLine("");
				sw->WriteLine("  Factura No  : " + noFactura);
				sw->WriteLine("  Serie       : " + txt_serie->Text->Trim()->ToUpper());
				sw->WriteLine("  Fecha       : " + dtp_fecha_fac->Value.ToString("dd/MM/yyyy"));
				sw->WriteLine("  ID Venta    : " + idVenta.ToString());
				sw->WriteLine("  ID Empleado : " + txt_id_empleado->Text->Trim());
				sw->WriteLine(simple);
				sw->WriteLine("  NIT         : " + txt_nit->Text->Trim());
				sw->WriteLine("  Cliente     : " + txt_nombre->Text->Trim());
				sw->WriteLine("  Direccion   : " + txt_direccion->Text->Trim());
				sw->WriteLine(doble);
				sw->WriteLine("");
				sw->WriteLine(String::Format("  {0,-6} {1,-25} {2,8} {3,5} {4,11}",
					"COD", "PRODUCTO", "PRECIO", "CANT", "SUBTOTAL"));
				sw->WriteLine("  " + simple);
				for each (DataGridViewRow ^ fila in datos_factura->Rows) {
					String^ prod = fila->Cells[1]->Value->ToString();
					if (prod->Length > 25) prod = prod->Substring(0, 22) + "...";
					sw->WriteLine(String::Format("  {0,-6} {1,-25} {2,8} {3,5} {4,11}",
						fila->Cells[0]->Value->ToString(), prod,
						fila->Cells[2]->Value->ToString(),
						fila->Cells[3]->Value->ToString(),
						fila->Cells[4]->Value->ToString()));
				}
				sw->WriteLine("  " + simple);
				sw->WriteLine(String::Format("  {0,49}", "TOTAL:   Q " + totalFactura.ToString("F2")));
				sw->WriteLine("");
				sw->WriteLine(doble);
				sw->WriteLine("              Gracias por su compra");
				sw->WriteLine("       Conserve este comprobante para cualquier");
				sw->WriteLine("              reclamo o devolucion.");
				sw->WriteLine(doble);
			}
			finally { sw->Close(); }
		}

		void LimpiarFormulario() {
			datos_factura->Rows->Clear();
			totalFactura = 0.0;
			lbl_total_monto->Text = "Q 0.00";
			txt_serie->Clear();
			txt_no_factura->Clear();
			txt_id_venta->Text = "Auto";
			txt_id_empleado->Clear();
			txt_nit->Clear();
			txt_nombre->Clear();
			txt_direccion->Clear();
			txt_nombre->ReadOnly = false;
			txt_direccion->ReadOnly = false;
			txt_nombre->ForeColor = System::Drawing::Color::White;
			txt_direccion->ForeColor = System::Drawing::Color::White;
			txt_codigo->Clear();
			txt_cantidad->Text = "1";
			dtp_fecha_fac->Value = System::DateTime::Now;
			clienteExistente = false;
		}

		System::Void datos_factura_CellContentClick(System::Object^ sender,
			System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		}
		System::Void panel_productos_Paint(System::Object^ sender,
			System::Windows::Forms::PaintEventArgs^ e) {
		}
	};
}