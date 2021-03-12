package packlib.business.custom;

import packlib.business.SuperBO;
import packlib.dto.MemberDTO;

import java.sql.SQLException;
import java.util.List;

public interface ManageMemberBO extends SuperBO {

    List<MemberDTO> getMember() throws SQLException;

    boolean createMember(MemberDTO dto) throws SQLException;

    boolean updateMember(MemberDTO dto) throws SQLException;

    boolean deleteMember(String customerID) throws SQLException;

    MemberDTO findMember(String id) throws SQLException;
}
