

public interface IPaper
{
    String colour;
    String quality;

    String Draw();
    String Shred();

    void setColour(String color) {
        this.colour = color;
    }
    void setQuality(String quality) {
        this.quality = quality;
    }

    String getColour() {
        return this.colour;
    }

    String getQuality() {
        return this.quality;
    }
}


public abstract class Notebook extends IPaper
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
    void setColour(String color) {
        this.colour = color;
    }
    void setQuality(String quality) {
        this.quality = quality;
    }

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

    String getColour() {
        return this.colour;
    }

    String getQuality() {
        return this.quality;
    }
}

public class DrawingNotebook extends Notebook
    {
        public String CoverColour;
        public String Type;
        public String Orientation;
        public Boolean HasExamples;
        
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

        public String Draw()
        {
            return "Draw something";
        }

        public String DrawPortrait()
        {
            return "Draw portrait";
        }
        
        public String DrawView()
        {
            return "Draw view";
        }

        public String Flipping()
        {
            return "Flipping drawing notebook";
        }
    }
