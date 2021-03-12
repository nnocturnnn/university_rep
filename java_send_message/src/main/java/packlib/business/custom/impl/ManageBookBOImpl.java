package packlib.business.custom.impl;

import packlib.business.Converter;
import packlib.business.custom.ManageBookBO;
import packlib.dao.DAOFactory;
import packlib.dao.custom.BookDAO;
import packlib.dto.BookDTO;

import java.sql.SQLException;
import java.util.List;

public class ManageBookBOImpl implements ManageBookBO {

    private BookDAO bookDAO;

    public ManageBookBOImpl() {
        bookDAO = DAOFactory.getInstance().getDAO(DAOFactory.DAOTypes.BOOK);
    }

    public List<BookDTO> getBook() throws SQLException {
        return bookDAO.findAll().map(Converter::<BookDTO>getDTOList).get();
    }

    public boolean createBook(BookDTO dto) throws SQLException {
        return bookDAO.save(Converter.getEntity(dto));
    }

    public boolean updateBook(BookDTO dto) throws SQLException {
        return bookDAO.update(Converter.getEntity(dto));
    }

    public boolean deleteBook(String code) throws SQLException {
        return bookDAO.delete(code);
    }

    public BookDTO findBook(String bookCode) throws SQLException {
        return bookDAO.find(bookCode).map(Converter::<BookDTO>getDTO).orElse(null);
    }
}
