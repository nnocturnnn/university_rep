package packlib.business;

import packlib.business.custom.impl.ManageAuthorBOImpl;
import packlib.business.custom.impl.ManageBookBOImpl;
import packlib.business.custom.impl.ManageIssueBooksBOImpl;
import packlib.business.custom.impl.ManageMemberBOImpl;

public class BOFactory {

    private static BOFactory boFactory;

    private BOFactory() {

    }

    public static BOFactory getInstance() {
        if (boFactory == null) {
            boFactory = new BOFactory();
        }
        return boFactory;
    }

    public <T extends SuperBO> T getBO(BOTypes boTypes) {
        switch (boTypes) {
            case MANAGE_AUTHOR:
                return (T) new ManageAuthorBOImpl();
            case MANAGE_BOOK:
                return (T) new ManageBookBOImpl();
            case MANAGE_ISSUEBOOKS:
                return (T) new ManageIssueBooksBOImpl();
            case MANAGE_MEMBER:
                return (T) new ManageMemberBOImpl();
            default:
                return null;

        }
    }

    public enum BOTypes {
        MANAGE_AUTHOR, MANAGE_BOOK, MANAGE_ISSUEBOOKS, MANAGE_MEMBER;
    }
}
