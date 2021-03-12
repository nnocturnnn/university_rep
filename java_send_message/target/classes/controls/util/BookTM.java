package com.ijse.sys.view.util;

public class BookTM {

    private String book_id;
    private String book_title;
    private String author_id;
    private String book_available;

    public BookTM() {
    }

    public BookTM(String book_id, String book_title, String author_id, String book_available) {
        this.setBook_id(book_id);
        this.setBook_title(book_title);
        this.setAuthor_id(author_id);
        this.setBook_available(book_available);
    }


    public String getBook_id() {
        return book_id;
    }

    public void setBook_id(String book_id) {
        this.book_id = book_id;
    }

    public String getBook_title() {
        return book_title;
    }

    public void setBook_title(String book_title) {
        this.book_title = book_title;
    }

    public String getAuthor_id() {
        return author_id;
    }

    public void setAuthor_id(String author_id) {
        this.author_id = author_id;
    }

    public String getBook_available() {
        return book_available;
    }

    public void setBook_available(String book_available) {
        this.book_available = book_available;
    }

    @Override
    public String toString() {
        return "BookTM{" +
                "book_id='" + book_id + '\'' +
                ", book_title='" + book_title + '\'' +
                ", author_id='" + author_id + '\'' +
                ", book_available='" + book_available + '\'' +
                '}';
    }
}
