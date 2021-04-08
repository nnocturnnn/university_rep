package f_app.demo;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class MainController {

    @RequestMapping(value = "/landingpage", method = RequestMethod.GET)
    public String land() {
        return "landingpage";
    }
    @RequestMapping(value = "/datapage", method = RequestMethod.POST)
    public String getForm(@ModelAttribute("SpringWeb")Title title,ModelMap model) {
        model.addAttribute("name", title.getName());
        model.addAttribute("age", title.getSubName());
        return "formpage";
    }
    @RequestMapping(value = "/formpage", method = RequestMethod.GET)
    public ModelAndView student() {
        return new ModelAndView("formpage", "command", new Title());
    }


}