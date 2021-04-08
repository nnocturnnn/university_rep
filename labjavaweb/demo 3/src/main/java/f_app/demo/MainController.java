package f_app.demo;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.servlet.ModelAndView;
import java.nio.file.Path;
import java.nio.file.*;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

@Controller
public class MainController {

    @RequestMapping(value = "/landingpage", method = RequestMethod.GET)
    public String land() {
        return "landingpage";
    }
    @RequestMapping(value = "/formpage", method = RequestMethod.POST) 
    public String getForm(Title title) throws Exception {
        String textToAppend = title.toFile();
        Path path = Paths.get(Paths.get(".").toAbsolutePath().normalize().toString() + "/samplefile.txt");
        Files.write(path, textToAppend.getBytes(), StandardOpenOption.APPEND);
        return "formpage";
    }
    @RequestMapping(value = "/formpage", method = RequestMethod.GET)
    public ModelAndView formget() {
        return new ModelAndView("formpage");
    }
    @RequestMapping(value = "/datapage", method = RequestMethod.GET)
    public ModelAndView data() {
        List<Title> titlist = new ArrayList<>();
        BufferedReader reader;
		try {
			reader = new BufferedReader(new FileReader(Paths.get(".").toAbsolutePath().normalize().toString() + "/samplefile.txt"));
			String line = reader.readLine();
			while (line != null) {
                Title tit = new Title();
                String[] arry = line.split(" ");
                tit.setName(arry[0]);
                tit.setSubName(arry[1]);
                tit.setAge(arry[2]);
                tit.setFather(arry[3]);
                titlist.add(tit);
				line = reader.readLine();
			}
			reader.close();
		} catch (IOException e) {
			e.printStackTrace();
        }
        ModelAndView mv = new ModelAndView();
        mv.setViewName("datapage");
        mv.addObject("empList", titlist);
        return mv;
    }


}