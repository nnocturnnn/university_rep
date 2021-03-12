package packlib.dao.custom.impl;

import packlib.dao.CrudUtil;
import packlib.dao.custom.AuthorDAO;
import packlib.entity.Author;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class AuthorDAOImpl implements AuthorDAO {

    public Optional<Author> find(String authorId) throws SQLException {
        ResultSet rst = CrudUtil.execute("SELECT * FROM author WHERE author_id = ?", authorId);
        Author a = null;
        if (rst.next()) {
            a = new Author(rst.getString("author_id"),
                    rst.getString("author_name"));
        }
        return Optional.ofNullable(a);

    }

    public Optional<List<Author>> findAll() throws SQLException {
        ArrayList<Author> alAuthor = new ArrayList<>();
        ResultSet rst = CrudUtil.execute("SELECT * FROM author");
        while (rst.next()) {
            String author_id = rst.getString(1);
            String author_name = rst.getString(2);
            Author author = new Author(author_id, author_name);
            alAuthor.add(author);
        }
        return Optional.ofNullable(alAuthor);
    }

    public boolean save(Author author) throws SQLException {
        return CrudUtil.<Integer>execute("INSERT INTO author VALUES (?,?)", //1
                author.getAuthor_id(), author.getAuthor_name()) > 0;
    }

    public boolean update(Author author) throws SQLException {
        return CrudUtil.<Integer>execute("UPDATE author SET author_name = ?",
             author.getAuthor_name()) > 0;
    }

    public boolean delete(String author_id) throws SQLException {
        return CrudUtil.<Integer>execute("DELETE FROM author WHERE author_id = ?", author_id) > 0;
    }

}
