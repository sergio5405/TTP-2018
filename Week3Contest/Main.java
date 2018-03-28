import java.util.*;

public class Main {
	public static String newString(String old){
		StringBuilder newS = new StringBuilder();

		int sum = 0;

		for (int i=0; i<old.length(); i++) {
			char c = old.charAt(i);
			switch(c){
				case ' ':
					break;
				case '.':
					sum+=1;
					break;
				case '-':
					sum+=5;
					break;
				case ':':
					sum+=2;
					break;
				case '=':
					sum+=10;
					break;
				default:
					newS.append(sum);
					newS.append(c);
					sum = 0;
			}
		}

		newS.append(sum);

		return newS.toString();
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int nOper = sc.nextInt();
		sc.nextLine();
		String morseStr = sc.nextLine();
		String equation = newString(morseStr);
		int result = compute(equation);
		System.out.println(result);
	}

	public static int compute(String equation) {
		int result = 0;
		String sumas[] = equation.split("\\+");
		for (String multipl : sumas) {
			String []multiplicas = multipl.split("\\*");
			int multiplResult = 1;
			for (String operand : multiplicas) {
				multiplResult *= Integer.parseInt(operand);
			}
			result += multiplResult;
		}
		return result;
	}

}