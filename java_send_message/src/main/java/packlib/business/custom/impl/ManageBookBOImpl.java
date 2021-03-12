package com.ijse.sys.business.custom.impl;

import com.ijse.sys.business.Converter;
import com.ijse.sys.business.custom.ManageBookBO;
import com.ijse.sys.dao.DAOFactory;
import com.ijse.sys.dao.custom.BookDAO;
import com.ijse.sys.dto.BookDTO;

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
