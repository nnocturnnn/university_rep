package packlib.dao.custom.impl;

import packlib.dao.CrudUtil;
import packlib.dao.custom.MemberDAO;
import packlib.entity.Member;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class MemberDAOImpl implements MemberDAO {

    public Optional<Member> find(String member_id) throws SQLException {
        ResultSet rst = CrudUtil.execute("SELECT * FROM member WHERE member_id = ?", member_id);
        Member m = null;
        if (rst.next()) {
            m = new Member(rst.getString("member_id"), rst.getString("member_name"),
                    rst.getString("member_address"), rst.getString("member_type"),
                    rst.getString("member_contactNo"));
        }
        return Optional.ofNullable(m);
    }

    public Optional<List<Member>> findAll() throws SQLException {
        ArrayList<Member> alMember = new ArrayList<>();
        ResultSet rst = CrudUtil.execute("SELECT * FROM member");
        while (rst.next()) {
            String member_id = rst.getString(1);
            String member_name = rst.getString(2);
            String member_address = rst.getString(3);
            String member_type = rst.getString(4);
            String contactNo = rst.getString(5);
            Member member = new Member(member_id, member_name, member_address, member_type, contactNo);
            alMember.add(member);
        }
        return Optional.ofNullable(alMember);
    }

    public boolean save(Member member) throws SQLException {
        return CrudUtil.<Integer>execute("INSERT INTO member VALUES (?,?,?,?,?)",
                member.getMember_id(), member.getMember_name(), member.getMember_address(), member.getMember_type(),
                member.getMember_contactNo()) > 0;
    }

    public boolean update(Member member) throws SQLException {
        return CrudUtil.<Integer>execute("UPDATE member SET member_id = ?, member_name =? , member_address = ? ," +
                        "member_type = ?, member_contactNo = ?", member.getMember_id(), member.getMember_name(), member.getMember_address(),
                member.getMember_type(), member.getMember_contactNo()) > 0;
    }

    public boolean delete(String member_id) throws SQLException {
        return CrudUtil.<Integer>execute("DELETE FROM member WHERE member_id = ?", member_id) > 0;
    }
}
