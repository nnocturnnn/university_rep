package packlib.entity;

public class IssueBooks extends SuperEntity {

    private IssueBooksPK issueBooksPK;
    private String issue_date;
    private String return_date;

    public IssueBooks() {
    }

    public IssueBooks(IssueBooksPK issueBooksPK, String issue_date, String return_date) {
        this.setIssueBooksPK(issueBooksPK);
        this.setIssue_date(issue_date);
        this.setReturn_date(return_date);
    }

    public IssueBooks(String bookId, String memberId, String issue_date, String return_date) {
        this.issueBooksPK = new IssueBooksPK(bookId, memberId);
        this.issue_date = issue_date;
        this.return_date = return_date;
    }




    public IssueBooksPK getIssueBooksPK() {
        return issueBooksPK;
    }

    public void setIssueBooksPK(IssueBooksPK issueBooksPK) {
        this.issueBooksPK = issueBooksPK;
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
        return "IssueBooks{" +
                "issueBooksPK=" + issueBooksPK +
                ", issue_date='" + issue_date + '\'' +
                ", return_date='" + return_date + '\'' +
                '}';
    }
}
