
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

public class StringReader extends JFrame {

    public JButton inputButton; // кнопка
    public JLabel label; // лейбл
    public JTextField textField; // поле ввода

    public StringReader(String title) {
        Scanner s = null;
        try {
            s = new Scanner(new File("text.txt")); // читаем файл
        } catch (FileNotFoundException e) { // обрабатываем ошибку
            e.printStackTrace(); // выводим ошибку
        }
        ArrayList<String> list = new ArrayList<String>(); // создаем список
        while (s.hasNextLine()){ // добавляем его построчно в список
            list.add(s.nextLine());
        }
        s.close(); // закрываем файл

        JPanel panel = new JPanel(); // создаем панельку
        panel.setBorder(new EmptyBorder(10, 10, 10, 10)); // границы
        panel.setLayout(new BorderLayout());

        label = new JLabel("Проста програма"); // добавляем лейбл
        inputButton = new JButton("Кнопка"); // добавляем кнопку
        textField = new JTextField(""); // добавляем поле

        panel.add(textField, BorderLayout.NORTH); // все это на панельку
        panel.add(label);
        panel.add(inputButton, BorderLayout.SOUTH);

        setContentPane(panel);
        setPreferredSize(new Dimension(300, 150));
        pack();



        inputButton.addActionListener(new ActionListener() { // слушаем действие кнопки и выводим по строки ищ файла
            int counter = 0;
            public void actionPerformed(ActionEvent arg0) {
                textField.setText(list.get(counter++));
                if (list.size() == counter) {
                    counter = 0;
                }
            }
        });

        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

}