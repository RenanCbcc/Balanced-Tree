public enum Severity {
	MINIMUM(1, "MINIMUN"), LITTLE(2, "LITTLE"), MEDIUM(3, "MEDIUM"), HIGH(4, "HIGH"), EXTREMELY(5, "EXTREMELY");

	private int indicator;
	private String description;

	Severity(int indicator, String description) {
		this.indicator = indicator;
		this.description = description;
	}

	public int getIndicator() {
		return this.indicator;
	}

	public String getDescription() {
		return this.description;
	}
}
