package packlib.business.custom;

import packlib.business.SuperBO;
import packlib.dto.BookDTO;

import java.sql.SQLException;
import java.util.List;

public interface ManageBookBO extends SuperBO {


    List<BookDTO> getBook() throws SQLException;

    boolean createBook(BookDTO dto) throws SQLException;

    boolean updateBook(BookDTO dto) throws SQLException;

    boolean deleteBook(String authorID) throws SQLException;

    BookDTO findBook(String id) throws SQLException;
}
