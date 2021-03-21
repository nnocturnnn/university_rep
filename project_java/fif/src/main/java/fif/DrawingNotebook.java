package fif;

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
