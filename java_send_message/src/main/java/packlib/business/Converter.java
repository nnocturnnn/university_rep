package packlib.business;

import packlib.dto.*;
import packlib.entity.*;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class Converter {

    public static <T extends SuperDTO> T getDTO(SuperEntity entity) {
        if (entity instanceof Author) {
            Author a = (Author) entity;
            return (T) new AuthorDTO(a.getAuthor_id(), a.getAuthor_name());
        } else if (entity instanceof Book) {
            Book b = (Book) entity;
            return (T) new BookDTO(b.getBook_id(), b.getBook_title(), b.getAuthor_id(), b.getBook_available());
        } else if (entity instanceof IssueBooks) {
            IssueBooks i = (IssueBooks) entity;
            return (T) new IssueBooksDTO(i.getIssueBooksPK().getBook_id(), i.getIssueBooksPK().getMember_id(), i.getIssue_date(), i.getReturn_date());
        } else if (entity instanceof Member) {
            Member m = (Member) entity;
            return (T) new MemberDTO(m.getMember_id(), m.getMember_name(), m.getMember_address(), m.getMember_type(), m.getMember_contactNo());
        } else {
            throw new RuntimeException("This entity can't be converted to a DTO");
        }
    }

    public static <T extends SuperEntity> T getEntity(SuperDTO dto) {
        if (dto instanceof AuthorDTO) {
            AuthorDTO a = (AuthorDTO) dto;
            return (T) new Author(a.getAuthor_id(), a.getAuthor_name());
        } else if (dto instanceof BookDTO) {
            BookDTO b = (BookDTO) dto;
            return (T) new Book(b.getBook_id(), b.getBook_title(), b.getAuthor_id(), b.getBook_available());
        } else if (dto instanceof IssueBooksDTO) {
            IssueBooksDTO i = (IssueBooksDTO) dto;
            return (T) new IssueBooks(i.getBook_id(), i.getMember_id(), i.getIssue_date(), i.getReturn_date());
        } else if (dto instanceof MemberDTO) {
            MemberDTO m = (MemberDTO) dto;
            return (T) new Member(m.getMember_id(), m.getMember_name(), m.getMember_address(), m.getMember_type(), m.getMember_contactNo());
        } else {
            throw new RuntimeException("This DTO can't be converted to an entity");
        }
    }

//    public static <T extends SuperDTO> List<T> getDTOList(List<? extends SuperEntity> entities) {
//        SuperEntity o = entities.get(0);
//        if (o instanceof Author) {
//            List<AuthorDTO> dtos = new ArrayList<>();
//            for (Object e : entities) {
//                Author a = (Author) e;
//                dtos.add((AuthorDTO) getDTO(a));
//            }
//            return (List<T>) dtos;
//        } else if (o instanceof Book) {
//            List<BookDTO> dtos = new ArrayList<>();
//            for (Object e : entities) {
//                Book b = (Book) e;
//                dtos.add((BookDTO) getDTO(b));
//            }
//            return (List<T>) dtos;
//        } else if (o instanceof IssueBooks) {
//            List<IssueBooksDTO> dtos = new ArrayList<>();
//            for (Object e : entities) {
//                IssueBooks i = (IssueBooks) e;
//                dtos.add((IssueBooksDTO) getDTO(i));
//            }
//            return (List<T>) dtos;
//        } else if (o instanceof Member) {
//            List<MemberDTO> dtos = new ArrayList<>();
//            for (Object e : entities) {
//                Member m = (Member) e;
//                dtos.add((MemberDTO) getDTO(m));
//            }
//            return (List<T>) dtos;
//        }
//        throw new RuntimeException("This entity list can't be converted to a DTO list");
//
//    }

//    public static <T extends SuperEntity> List<T> getEntityList(List<? extends SuperDTO> dtos) {
//        SuperDTO d = dtos.get(0);
//        if (d instanceof AuthorDTO) {
//            List<Author> list = new ArrayList<>();
//            dtos.forEach(c -> {
//                list.add(getEntity(c));
//            });
//            return (List<T>) list;
//        } else if (d instanceof BookDTO) {
//            List<Book> list = new ArrayList<>();
//            dtos.forEach(c -> {
//                list.add(getEntity(c));
//            });
//            return (List<T>) list;
//        } else if (d instanceof IssueBooksDTO) {
//            List<IssueBooks> list = new ArrayList<>();
//            dtos.forEach(c -> {
//                list.add(getEntity(c));
//            });
//            return (List<T>) list;
//        } else if (d instanceof MemberDTO) {
//            List<Member> list = new ArrayList<>();
//            dtos.forEach(c -> {
//                list.add(getEntity(c));
//            });
//            return (List<T>) list;
//        } else {
//            throw new RuntimeException("This dto list can't be converted to an entity list");
//        }
//    }

    public static <T extends SuperDTO> List<T> getDTOList(List<? extends SuperEntity> entities) {
        return entities.stream().map(Converter::<T>getDTO).collect(Collectors.toList());
    }

    public static <T extends SuperEntity> List<T> getEntityList(List<? extends  SuperDTO> dtos) {
        return dtos.stream().map(Converter::<T>getEntity).collect(Collectors.toList());
    }

    /*public static <T extends SuperDTO> List<T> getDTOList(List<? extends SuperEntity> entities) {
        return entities.stream().map(Converter::<T>getDTO).collect(Collectors.toList());
    }

    public static <T extends SuperEntity> List<T> getEntityList(List<? extends SuperDTO> dtos) {
        return dtos.stream().map(Converter::<T>getEntity).collect(Collectors.toList());

    }*/


}
