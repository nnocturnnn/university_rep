
import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.geom.Line2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;

public class DrawingArea extends JPanel
{
    private static final int DA_WIDTH = 700; //ширина хоста
    private static final int DA_HEIGHT = 500; // высота холста
    private static final Color DA_BGCOLOR = Color.WHITE; // цвет фона
    private static final long serialVersionUID = 1L;


    ArrayList<Point> points = new ArrayList<>(); // массив точек

    private Color currentColor; // цвет кисти
    BufferedImage bImage = new BufferedImage(DA_WIDTH, DA_HEIGHT, BufferedImage.TYPE_INT_RGB);


    public DrawingArea() // функция для создания поля рисования
    {
        setBorder(BorderFactory.createLineBorder(Color.BLACK));

        Graphics g2d = bImage.getGraphics();

        g2d.setColor(DA_BGCOLOR); // ставим цвет

        g2d.fillRect(0,0,DA_WIDTH,DA_HEIGHT); //вызываем рамку

        g2d.dispose(); //  Disposes of this graphics context and releases any system resources that it is using

        addMouseListener(new MouseAdapter() {
            @Override
            public void mousePressed(MouseEvent e)
            { // слушаем кнопки мыши
                points.clear(); // очищаем список точек
                points.add(e.getPoint()); // добавляем точки на холст
            }
        });

        addMouseMotionListener(new MouseAdapter() {
            @Override
            public void mouseDragged(MouseEvent e)
            { // слушаем кнопки мыши
                points.add(e.getPoint()); // добавляем точки на холст
                repaint(); // перерисовываем если попадаем на уже существующую
            }
        });

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseReleased(MouseEvent e) { // слушаем кнопки мыши
                points.add(e.getPoint()); // добавляем точки на холст
                points.clear(); // очищаем список точек
                repaint(); // перерисовываем если попадаем на уже существующую
            }
        });
    }

    @Override
    public Dimension getPreferredSize()
    {
        return  new Dimension(DA_WIDTH,DA_HEIGHT);
    } // берем размер кисти

    @Override
    public void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        drawIntoBufferedImage();
        g.drawImage(bImage,0,0,null); //Draws as much of the specified image as is currently available. The image is drawn with its top-left corner at (x, y)
        freehandLines(g);
    }

    public void drawIntoBufferedImage()
    {
        Graphics g = bImage.getGraphics(); //This method returns a Graphics2D, but is here for backwards compatibility.
        freehandLines(g);
        g.dispose();
    }

    public void freehandLines(Graphics g) // рисуем линию по заданым точкам со списка
    {
        if(points != null && points.size()>1)
        {
            g.setColor(getCurrentColor());
            for(int i =0; i < points.size()-1;++i)
            {
                Graphics2D  g2d = (Graphics2D) g;
                ((Graphics2D)g).setStroke(new BasicStroke(widthPen));
                ((Graphics2D)g).draw(new Line2D.Float(points.get(i).x,points.get(i).y,points.get(i+1).x,points.get(i+1).y));
            }
        }
    }

    public void clearDrawings() // очищаем поле для рисования
    {
        if(points!=null)
        {
            points.clear();
            Graphics g = bImage.getGraphics();
            g.setColor(DA_BGCOLOR);
            g.fillRect(0, 0, DA_WIDTH, DA_WIDTH);
            g.dispose();
            repaint();
        }
    }

    public void setCurrentColor(Color currentColor) // выбираем нужный цвет
    {
        if(currentColor == null)
            currentColor = Color.BLACK;
        else
            this.currentColor = currentColor;
    }

    public Color getCurrentColor() // берем заданый цвет
    {
        if (currentColor == null)
            return Color.BLACK;
        else
            return currentColor;
    }

    public  void setWidth(int width) // выбираем размер кисти
    {
        if(!(width <=0 || width>=40)) widthPen=width;
        else
        {
            JOptionPane.showMessageDialog(this,"Ошибка, введите допустимое значение");
        }
    }

    public int getWidthPen() {
        return widthPen;
    }

    private int widthPen = 20;
}
