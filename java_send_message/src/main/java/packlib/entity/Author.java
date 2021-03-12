package com.ijse.sys.entity;

public class Author extends SuperEntity {

    private String author_id;
    private String author_name;

    public Author() {
    }

    public Author(String author_id, String author_name) {
        this.setAuthor_id(author_id);
        this.setAuthor_name(author_name);
    }


    public String getAuthor_id() {
        return author_id;
    }

    public void setAuthor_id(String author_id) {
        this.author_id = author_id;
    }

    public String getAuthor_name() {
        return author_name;
    }

    public void setAuthor_name(String author_name) {
        this.author_name = author_name;
    }

    @Override
    public String toString() {
        return "Author{" +
                "author_id='" + author_id + '\'' +
                ", author_name='" + author_name + '\'' +
                '}';
    }
}
