
import java.awt.*;
import javax.swing.*;

public class SimpleGUI extends JFrame
{
     DrawingArea area = new DrawingArea();

     public SimpleGUI()
     {
         setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
         setTitle("Simple paint"); // ставим название окна
         setResizable(false); // чтобы размер окна не можно было изменить
         setVisible(true); // чтобы окно было видно

         JPanel buttonContainer = new JPanel(); // добавляем кнопки
         JButton btnClear = new JButton("Clear"); // очищения
         JButton btnChangeWidth = new JButton("Change Width of pen"); // размера
         JButton btnColorChoose = new JButton("Choose color"); // выбора цвета
         JButton btnAbout = new JButton("About");

         buttonContainer.add(btnClear); // добавляем все эти кнопки в контейнер
         buttonContainer.add(btnColorChoose);
         buttonContainer.add(btnChangeWidth);
         buttonContainer.add(btnAbout);

         btnAbout.addActionListener(e-> // слуем кнопку и выводим сообщение
         {
             JOptionPane.showMessageDialog(area, "Simple paint","About",0 ,new ImageIcon());
         });

         btnChangeWidth.addActionListener(e->
         {
             int width = area.getWidthPen(); // получаем размерность кисти с помощью  showInputDialo
             try
             {
                 String text =JOptionPane.showInputDialog(area,"Please enter a width of pen([1-39]):",width);

                 width = new Integer(JOptionPane.showInputDialog(area,"Please enter a width of pen([1-39]):",width));
             }
             catch (NumberFormatException ex) // обрабатываем ошибку
             {

             }
            area.setWidth(width); // ставим размер кисти
         });

         btnColorChoose.addActionListener( e-> // получаем цвет кисти с помощью JColorChooser
         {
             JColorChooser jcc = new JColorChooser();
             Color c = jcc.showDialog(null,"Please select a color", Color.BLACK);
             area.setCurrentColor(c); // ставим цвет кисти
         });

         btnClear.addActionListener(e -> area.clearDrawings()); // слушаем кнопку очищения

         getContentPane().add(area); // добавляем на Панель поле для рисования
         getContentPane().add(buttonContainer, BorderLayout.PAGE_END); // добавляем на Панель поле с кнопками

         pack();

     }
}





