package packlib.dao.custom.impl;

import packlib.dao.CrudUtil;
import packlib.dao.custom.IssueBooksDAO;
import packlib.entity.IssueBooks;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class IssueBooksDAOImpl implements IssueBooksDAO {

    public Optional<IssueBooks> find(String member_id) throws SQLException {
        ResultSet rst = CrudUtil.execute("SELECT * FROM issuebooks WHERE member_id = ?", member_id);
        IssueBooks i = null;
        if (rst.next()) {
            i = new IssueBooks(rst.getString("book_id"),
                    rst.getString("member_id"), rst.getString("issue_date"),
                    rst.getString("return_date"));
        }
        return Optional.of(i);
    }

    public Optional<List<IssueBooks>> findAll() throws SQLException {
        ArrayList<IssueBooks> alIssueBooks = new ArrayList<>();
        ResultSet rst = CrudUtil.execute("SELECT * FROM issuebooks");
        while (rst.next()) {
            String book_id = rst.getString(1);
            String member_id = rst.getString(2);
            String issue_date = rst.getString(3);
            String return_date = rst.getString(4);
            IssueBooks issueBooks = new IssueBooks(book_id, member_id, issue_date, return_date);
            alIssueBooks.add(issueBooks);
        }
        return Optional.ofNullable(alIssueBooks);
    }

    public boolean save(IssueBooks issueBooks) throws SQLException {
        return CrudUtil.<Integer>execute("INSERT INTO issuebooks VALUES (?,?,?,?)",
                issueBooks.getIssueBooksPK().getBook_id(), issueBooks.getIssueBooksPK().getMember_id(), issueBooks.getIssue_date(), issueBooks.getReturn_date()) > 0;
    }

    public boolean update(IssueBooks issueBooks) throws SQLException {
        return CrudUtil.<Integer>execute("UPDATE issuebooks SET book_id = ?, issue_date = ?, return_date = ? WHERE member_id = ?", issueBooks.getIssueBooksPK().getBook_id(),
                issueBooks.getIssue_date(), issueBooks.getReturn_date(), issueBooks.getIssueBooksPK().getMember_id()) > 0;
    }

    //UPDATE book SET book_title = ?, author_id = ?,book_available = ? WHERE book_id = ?

    public boolean delete(String member_id) throws SQLException {
        return CrudUtil.<Integer>execute("DELETE FROM issuebooks WHERE member_id = ?", member_id) > 0;
    }
}
