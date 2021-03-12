package com.ijse.sys.view.util;

public class IssueOfBookTM {

    private String book_id;
    private String member_id;
    private String issue_date;
    private String return_date;

    public IssueOfBookTM() {
    }

    public IssueOfBookTM(String book_id, String member_id, String issue_date, String return_date) {
        this.setBook_id(book_id);
        this.setMember_id(member_id);
        this.setIssue_date(issue_date);
        this.setReturn_date(return_date);
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

    public String getIssue_date() {
        return issue_date;
    }

    public void setIssue_date(String issue_date) {
        this.issue_date = issue_date;
    }

    public String getReturn_date() {
        return return_date;
    }

    public void setReturn_date(String return_date) {
        this.return_date = return_date;
    }

    @Override
    public String toString() {
        return "IssueOfBookTM{" +
                "book_id='" + book_id + '\'' +
                ", member_id='" + member_id + '\'' +
                ", issue_date='" + issue_date + '\'' +
                ", return_date='" + return_date + '\'' +
                '}';
    }
}
