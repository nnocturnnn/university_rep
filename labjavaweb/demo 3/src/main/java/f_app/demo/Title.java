package f_app.demo;


public class Title {

    private String name;

    private String subName;

    private String age;

    private String father;

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSubName() {
        return this.subName;
    }

    public void setSubName(String subName) {
        this.subName = subName;
    }

    public String getAge() {
        return this.age;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public String getFather() {
        return this.father;
    }

    public void setFather(String father) {
        this.father = father;
    }

    public String toFile() {
        return this.name + " " + this.subName + " " + this.age + " " + this.father + "\n";
    }



}