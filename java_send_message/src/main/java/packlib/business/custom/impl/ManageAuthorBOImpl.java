package com.ijse.sys.business.custom.impl;

import com.ijse.sys.business.Converter;
import com.ijse.sys.business.custom.ManageAuthorBO;
import com.ijse.sys.dao.DAOFactory;
import com.ijse.sys.dao.custom.AuthorDAO;
import com.ijse.sys.dto.AuthorDTO;

import java.sql.SQLException;
import java.util.List;

public class ManageAuthorBOImpl implements ManageAuthorBO {

    private AuthorDAO authorDAO;

    public ManageAuthorBOImpl() {
        authorDAO = DAOFactory.getInstance().getDAO(DAOFactory.DAOTypes.AUTHOR);
    }


    @Override
    public List<AuthorDTO> getAuthor() throws SQLException {
        return authorDAO.findAll().map(Converter::<AuthorDTO>getDTOList).get();
    }

    @Override
    public boolean createAuthor(AuthorDTO dto) throws SQLException {
        return authorDAO.save(Converter.getEntity(dto));
    }

    @Override
    public boolean updateAuthor(AuthorDTO dto) throws SQLException {
        return authorDAO.update(Converter.getEntity(dto));
    }

    @Override
    public boolean deleteAuthor(String authorID) throws SQLException {
        return authorDAO.delete(authorID);
    }

    @Override
    public AuthorDTO findAuthor(String id) throws SQLException {
        return authorDAO.find(id).map(Converter::<AuthorDTO>getDTO).orElse(null);
    }
}
