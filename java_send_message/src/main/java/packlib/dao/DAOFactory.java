package packlib.dao;

import packlib.dao.custom.impl.*;

public class DAOFactory {

    private static DAOFactory daoFactory;

    private DAOFactory() {

    }

    public static DAOFactory getInstance() {
        if (daoFactory == null) {
            daoFactory = new DAOFactory();
        }

        return daoFactory;
    }

    public <T extends SuperDAO> T getDAO(DAOTypes daoTypes) {
        switch (daoTypes) {
            case AUTHOR:
                return (T) new AuthorDAOImpl();
            case BOOK:
                return (T) new BookDAOImpl();
            case ISSUEBOOKS:
                return (T) new IssueBooksDAOImpl();
            case MEMBER:
                return (T) new MemberDAOImpl();
            case QUERY:
                return (T) new QueryDAOImpl();
            default:
                return null;
        }
    }

    public enum DAOTypes {
        AUTHOR, BOOK, ISSUEBOOKS, MEMBER, QUERY;
    }


}
