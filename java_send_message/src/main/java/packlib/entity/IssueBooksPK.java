package packlib.entity;

public class IssueBooksPK {

    private String book_id;
    private String member_id;

    public IssueBooksPK() {
    }

    public IssueBooksPK(String book_id, String member_id) {
        this.setBook_id(book_id);
        this.setMember_id(member_id);
    }


    public String getBook_id() {
        return book_id;
    }

    public void setBook_id(String book_id) {
        this.book_id = book_id;
    }

    public String getMember_id() {
        return member_id;
    }

    public void setMember_id(String member_id) {
        this.member_id = member_id;
    }

    @Override
    public String toString() {
        return "IssueBooksPK{" +
                "book_id='" + book_id + '\'' +
                ", member_id='" + member_id + '\'' +
                '}';
    }
}
