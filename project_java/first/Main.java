package first;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.List;



public class Main {

	public static void main(String[] args) {
		LocalDate d=null;
		
		ProgramGuide programGuide = new ProgramGuide(d.now());
		
		programGuide.createTvChannel("1", LocalTime.of(8, 00), "New ");
		programGuide.createTvChannel("1", LocalTime.of(8, 00), "Ukraine");
		programGuide.createTvChannel("1", LocalTime.of(8, 30), "5C");
	
		programGuide.receiveProgram("1", programGuide.getTvChannel());
	}

}

public class ProgramGuide {
	private LocalDate date;
	private List<TvChannel> tvChannel = new ArrayList<TvChannel>();

	public ProgramGuide(LocalDate date) {
		super();
		this.date = date;
	}

	public ProgramGuide() {
		super();
	}

	public List<TvChannel> getTvChannel() {
		return tvChannel;
	}

	public class TvChannel {
		private String nameTv;
		private List<Program> program = new ArrayList<Program>();

		public void setNameTv(String nameTv) {
			this.nameTv = nameTv;
		}

		public String getNameTv() {
			return nameTv;
		}

		public class Program {
			private LocalTime timeBegin;
			private String nameProgram;

			public void setTimeBegin(LocalTime timeBegin) {
				this.timeBegin = timeBegin;
			}

			public void setNameProgram(String nameProgram) {
				this.nameProgram = nameProgram;
			}

			@Override
			public String toString() {
				return timeBegin + " - " + nameProgram ;
			}

		}

		public List<Program> createProgram(LocalTime timeB, String nameP) {
			Program p = new Program();
			p.setTimeBegin(timeB);
			p.setNameProgram(nameP);
			program.add(p);

			return program;
		}

		@Override
		public String toString() {
			return nameTv + ", program=" + program + "]";
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getEnclosingInstance().hashCode();
			result = prime * result + ((nameTv == null) ? 0 : nameTv.hashCode());
			result = prime * result + ((program == null) ? 0 : program.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			TvChannel other = (TvChannel) obj;
			if (!getEnclosingInstance().equals(other.getEnclosingInstance()))
				return false;
			if (nameTv == null) {
				if (other.nameTv != null)
					return false;
			} else if (!nameTv.equals(other.nameTv))
				return false;
			if (program == null) {
				if (other.program != null)
					return false;
			} else if (!program.equals(other.program))
				return false;
			return true;
		}

		private ProgramGuide getEnclosingInstance() {
			return ProgramGuide.this;
		}
	}

	public List<TvChannel> createTvChannel(String nameTv, LocalTime timeB, String nameP) {
		TvChannel tvCh = new TvChannel();
		tvCh.setNameTv(nameTv);
		tvCh.createProgram(timeB, nameP);
		tvChannel.add(tvCh);
		return tvChannel;
	}
	
	public void receiveProgram(String nameTv, List<TvChannel> tvCh) {
		TvChannel tvChan = new TvChannel();
		for (TvChannel tc: tvCh) {
			if(nameTv.equals(tc.getNameTv())){
				System.out.println(tc);
			}
		}
		
	}

	@Override
	public String toString() {
		return date + "  " + tvChannel ;
	}
}
