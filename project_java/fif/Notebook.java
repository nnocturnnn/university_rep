package fif;

public abstract class Notebook implements IPaper
{
    public String colour;
    public String quality;
    public String CoverColour;
    public String Type;

    public abstract String Draw();

    public abstract String Flipping();

    public String Shred()
    {
        return "Shred Notebook";
    }
    // void setColour(String colour) {
    //     this.colour = colour;
    // }
    // void setQuality(String quality) {
    //     this.quality = quality;
    // }

    void setCoverColour(String CoverColour) {
        this.CoverColour = CoverColour;
    }
    void setType(String type) {
        this.Type = type;
    }

    String getCoverColour() {
        return this.CoverColour;
    }

    String getType() {
        return this.Type;
    }

    // String getColour() {
    //     return this.colour;
    // }

    // String getQuality() {
    //     return this.quality;
    // }
}
