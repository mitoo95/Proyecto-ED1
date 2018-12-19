using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;

using GMap.NET;
using GMap.NET.MapProviders;
using GMap.NET.WindowsForms;
using GMap.NET.WindowsForms.Markers;



namespace Mapa{

    public partial class Form1 : Form{

        [DllImport("C: \\Users\\mitoo\\Documents\\Proyecto Mapa\\MapaDLL\\Debug\\MapaDLL.dll")]
        public static extern void CrearPuntosDLL(int id, string nombre, double latx, double lony);

        [DllImport("C: \\Users\\mitoo\\Documents\\Proyecto Mapa\\MapaDLL\\Debug\\MapaDLL.dll")]
        public static extern void CrearRutasDLL(int idP1, int idP2);

        [DllImport("C: \\Users\\mitoo\\Documents\\Proyecto Mapa\\MapaDLL\\Debug\\MapaDLL.dll")]
        public static extern void LeerPuntosDLL(string buff, int id);

        [DllImport("C: \\Users\\mitoo\\Documents\\Proyecto Mapa\\MapaDLL\\Debug\\MapaDLL.dll")]
        public static extern void LeerRutasDLL(string buff, int id);

        [DllImport("C: \\Users\\mitoo\\Documents\\Proyecto Mapa\\MapaDLL\\Debug\\MapaDLL.dll")]
        public static extern bool BuscarPuntosDLL();

        GMarkerGoogle marker;
        GMapOverlay markerOverlay;
        DataTable dt;

        int filaSeleccionada = 0;
        double latInicial = 15.5068258725672;
        double lngInicial = -88.0372667312622;

        public Form1(){

            InitializeComponent();

        }

        private void Form1_Load(object sender, EventArgs e){

            dt = new DataTable();
            dt.Columns.Add(new DataColumn("ID", typeof(int)));
            dt.Columns.Add(new DataColumn("Descripcion",typeof(string)));
            dt.Columns.Add(new DataColumn("Lat", typeof(double)));
            dt.Columns.Add(new DataColumn("Long", typeof(double)));

            //Set autoincrement true for the first column
            dt.Columns["ID"].AutoIncrement = true;

            //Set the starting or seed value
            dt.Columns["ID"].AutoIncrementSeed = 1;

            //Set the increment value
            dt.Columns["ID"].AutoIncrementStep = 1;

            //Insertando datos al dt para mostrar en la lista
            dt.Rows.Add(1, "Fuente Luminosa", latInicial, lngInicial);
            dataGridView1.DataSource = dt;

            //desactivar las columnas de lat y long
            dataGridView1.Columns[2].Visible = false;
            dataGridView1.Columns[3].Visible = false;

            gMapControl1.DragButton = MouseButtons.Left;
            gMapControl1.CanDragMap = true;
            gMapControl1.MapProvider = GMapProviders.GoogleMap;
            gMapControl1.Position = new PointLatLng(latInicial, lngInicial);
            gMapControl1.MinZoom = 0;
            gMapControl1.MaxZoom = 24;
            gMapControl1.Zoom = 16;
            gMapControl1.AutoScroll = true;

            //Marcador
            markerOverlay = new GMapOverlay("Marcador");
            marker = new GMarkerGoogle(new PointLatLng(latInicial, lngInicial), GMarkerGoogleType.red);
            markerOverlay.Markers.Add(marker);//agregamos marcador al mapa

            //tooltip para el marcador
            marker.ToolTipMode = MarkerTooltipMode.OnMouseOver;
            marker.ToolTipText = string.Format("Ubicacion: \n Latitud: {0} \n Longitud: {1}", latInicial, lngInicial);

            //agregar mapa y marcador al map control
            gMapControl1.Overlays.Add(markerOverlay);
        }

        private void SeleccionarRegistro(object sender, DataGridViewCellMouseEventArgs e){

            filaSeleccionada = e.RowIndex; //Fila Seleccionada
            // Recuperamos datos del grid y asignamos a los txtbox
            txtID.Text = dataGridView1.Rows[filaSeleccionada].Cells[0].Value.ToString();
            txtDescripcion.Text = dataGridView1.Rows[filaSeleccionada].Cells[1].Value.ToString();
            txtLatitud.Text = dataGridView1.Rows[filaSeleccionada].Cells[2].Value.ToString();
            txtLongitud.Text = dataGridView1.Rows[filaSeleccionada].Cells[3].Value.ToString();
            //se asignan los valores del grid al marcador
            marker.Position = new PointLatLng(Convert.ToDouble(txtLatitud.Text), Convert.ToDouble(txtLongitud.Text));
            //se posiciona el foco del mapa en ese punto
            gMapControl1.Position = marker.Position;

        }

        private void gMapControl1_MouseDoubleClick(object sender, MouseEventArgs e){

            //se obtiene los datos de lat y lng del mapa donde usuario presiono
            double lat = gMapControl1.FromLocalToLatLng(e.X, e.Y).Lat;
            double lng = gMapControl1.FromLocalToLatLng(e.X, e.Y).Lng;

            //se posicionan en los txtboxes de lat y lng
            txtLatitud.Text = lat.ToString();
            txtLongitud.Text = lng.ToString();

            //creamos marcador para moverlo al lugar indicado
            marker.Position = new PointLatLng(lat, lng);
            //tooltip refresh
            marker.ToolTipText = string.Format("Ubicacion: \n Latitud: {0} \n Longitud: {1}", lat, lng);

        }

        private void btnAgregar_Click(object sender, EventArgs e){

            dt.Rows.Add(null, txtDescripcion.Text, txtLatitud.Text, txtLongitud.Text);

        }

        private void btnEliminar_Click(object sender, EventArgs e){

            dataGridView1.Rows.RemoveAt(filaSeleccionada);

        }

        private void btnGuardar_Click(object sender, EventArgs e){

            CrearPuntosDLL();

        }
    }
}
