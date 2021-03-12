package packlib.dto;

public class MemberDTO extends SuperDTO {

    private String member_id;
    private String member_name;
    private String member_address;
    private String member_type;
    private String member_contactNo;

    public MemberDTO() {
    }

    public MemberDTO(String member_id, String member_name, String member_address, String member_type, String member_contactNo) {
        this.setMember_id(member_id);
        this.setMember_name(member_name);
        this.setMember_address(member_address);
        this.setMember_type(member_type);
        this.setMember_contactNo(member_contactNo);
    }


    public String getMember_id() {
        return member_id;
    }

    public void setMember_id(String member_id) {
        this.member_id = member_id;
    }

    public String getMember_name() {
        return member_name;
    }

    public void setMember_name(String member_name) {
        this.member_name = member_name;
    }

    public String getMember_address() {
        return member_address;
    }

    public void setMember_address(String member_address) {
        this.member_address = member_address;
    }

    public String getMember_type() {
        return member_type;
    }

    public void setMember_type(String member_type) {
        this.member_type = member_type;
    }

    public String getMember_contactNo() {
        return member_contactNo;
    }

    public void setMember_contactNo(String member_contactNo) {
        this.member_contactNo = member_contactNo;
    }

    @Override
    public String toString() {
        return "MemberDTO{" +
                "member_id='" + member_id + '\'' +
                ", member_name='" + member_name + '\'' +
                ", member_address='" + member_address + '\'' +
                ", member_type='" + member_type + '\'' +
                ", member_contactNo='" + member_contactNo + '\'' +
                '}';
    }
}
