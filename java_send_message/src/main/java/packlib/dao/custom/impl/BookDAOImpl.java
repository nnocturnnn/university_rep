package packlib.dao.custom.impl;

import packlib.dao.CrudUtil;
import packlib.dao.custom.BookDAO;
import packlib.entity.Book;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class BookDAOImpl implements BookDAO {

    public Optional<Book> find(String bookId) throws SQLException {
        ResultSet rst = CrudUtil.execute("SELECT * FROM book WHERE book_id = ?", bookId);
        Book b = null;
        if (rst.next()) {
            b = new Book(rst.getString("book_id"),
                    rst.getString("book_title"),
                    rst.getString("author_id"),
                    rst.getString("book_available"));
        }
        return Optional.ofNullable(b);

    }

    public Optional<List<Book>> findAll() throws SQLException {
        ArrayList<Book> alBook = new ArrayList<>();
        ResultSet rst = CrudUtil.execute("SELECT * FROM book");
        while (rst.next()) {
            String book_id = rst.getString(1);
            String book_title = rst.getString(2);
            String author_id = rst.getString(3);
            String book_available = rst.getString(4);
            Book book = new Book(book_id, book_title, author_id, book_available);
            alBook.add(book);
        }
        return Optional.ofNullable(alBook);
    }

    public boolean save(Book book) throws SQLException {
        return CrudUtil.<Integer>execute("INSERT INTO book VALUES (?,?,?,?)",
                book.getBook_id(), book.getBook_title(), book.getAuthor_id(), book.getBook_available()) > 0;
    }

    public boolean update(Book book) throws SQLException {
        return CrudUtil.<Integer>execute("UPDATE book SET book_title = ?, author_id = ?,book_available = ? WHERE book_id = ?",  book.getBook_title(), book.getAuthor_id(),
                book.getBook_available(), book.getBook_id()) > 0;
    }

    public boolean delete(String book_id) throws SQLException {
        return CrudUtil.<Integer>execute("DELETE FROM book WHERE book_id = ?", book_id) > 0;
    }

}


