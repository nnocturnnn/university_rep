package packlib.business.custom;

import packlib.business.SuperBO;
import packlib.dto.IssueBooksDTO;

import java.sql.SQLException;
import java.util.List;

public interface ManageIssueBooksBO extends SuperBO {

    List<IssueBooksDTO> getIssueBooks() throws SQLException;

    boolean createIssueBooks(IssueBooksDTO dto) throws SQLException;

    boolean updateIssueBooks(IssueBooksDTO dto) throws SQLException;

    boolean deleteIssueBooks(String authorID) throws SQLException;

    IssueBooksDTO findIssueBooks(String id) throws SQLException;
}
