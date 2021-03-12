package packlib.business.custom.impl;

import packlib.business.Converter;
import packlib.business.custom.ManageMemberBO;
import packlib.dao.DAOFactory;
import packlib.dao.custom.MemberDAO;
import packlib.dto.MemberDTO;

import java.sql.SQLException;
import java.util.List;

public class ManageMemberBOImpl implements ManageMemberBO {

    private MemberDAO memberDAO;

    public ManageMemberBOImpl() {
        memberDAO = DAOFactory.getInstance().getDAO(DAOFactory.DAOTypes.MEMBER);
    }

    public List<MemberDTO> getMember() throws SQLException {
        return memberDAO.findAll().map(Converter::<MemberDTO>getDTOList).get();
    }

    public boolean createMember(MemberDTO dto) throws SQLException {
        return memberDAO.save(Converter.getEntity(dto));
    }

    public boolean updateMember(MemberDTO dto) throws SQLException {
        return memberDAO.update(Converter.getEntity(dto));
    }

    public boolean deleteMember(String code) throws SQLException {
        return memberDAO.delete(code);
    }

    public MemberDTO findMember(String memberId) throws SQLException {
        return memberDAO.find(memberId).map(Converter::<MemberDTO>getDTO).orElse(null);
    }
}
