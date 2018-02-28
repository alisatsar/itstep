  public partial class Form2 : Form
    {
        DbConnection connection;
        DbDataAdapter adapter;

       

        public Form2()
        {
            InitializeComponent();
            connection = new SqlConnection();
            connection.ConnectionString = @"Data Source=DESKTOP-UV8M9K6\SQLEXPRESS;" +
                        "Initial Catalog=English;" +
                        "Integrated Security=yes";

            adapter = new SqlDataAdapter();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'englishDataSet.Theme' table. You can move, or remove it, as needed.
            this.themeTableAdapter.Fill(this.englishDataSet.Theme);         

        }

        private void Add_Click(object sender, EventArgs e)
        {
            String phrase;
            String translation;
            if (PhraseTB.Text.Length != 0 && TranslationTB.Text.Length != 0)
            {
                phrase = PhraseTB.Text;
                translation = TranslationTB.Text;

                DbCommand insert = new SqlCommand();
                insert.Connection = connection;
                insert.CommandText = "insert into AllWordsAndPhrase (Phrase, Translation, DateAdded, IdTheme, IdType) values" +
                   " (@ph, @tr, GETDATE(), @th, @type)";
                DbParameter phrasePar;
                phrasePar = new SqlParameter("ph", SqlDbType.NVarChar, 255);
                phrasePar.SourceColumn = "Phrase";
                insert.Parameters.Add(phrasePar);
                DbParameter translationPar;
                translationPar = new SqlParameter("tr", SqlDbType.NVarChar, 255);
                translationPar.SourceColumn = "Translation";
                insert.Parameters.Add(translationPar);
                DbParameter themePar;
                themePar = new SqlParameter("th", SqlDbType.Int);

                //themePar.SourceColumn = comboBox1.Selec
                insert.Parameters.Add(translationPar);
                //adapter.InsertCommand = insert;
            }


        }

     
    }
