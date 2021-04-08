package f_app.demo;

import f_app.demo.Title;
import org.springframework.data.repository.CrudRepository;

import java.util.List;

public interface Repos extends CrudRepository<Title, Long> {

}