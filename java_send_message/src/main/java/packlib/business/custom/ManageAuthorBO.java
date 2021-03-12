package com.ijse.sys.business.custom;

import com.ijse.sys.business.SuperBO;
import com.ijse.sys.dto.AuthorDTO;

import java.sql.SQLException;
import java.util.List;

public interface ManageAuthorBO extends SuperBO {

    List<AuthorDTO> getAuthor() throws SQLException;

    boolean createAuthor(AuthorDTO dto) throws SQLException;

    boolean updateAuthor(AuthorDTO dto) throws SQLException;

    boolean deleteAuthor(String authorID) throws SQLException;

    AuthorDTO findAuthor(String id) throws SQLException;
}
