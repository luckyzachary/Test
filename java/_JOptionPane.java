import javax.swing.JOptionPane;
public class _JOptionPane {
	public static void main(String[] args){
		JOptionPane.showInputDialog("message");
		JOptionPane.showInputDialog("message", "input");
		JOptionPane.showInputDialog(null, "input", "title", JOptionPane.QUESTION_MESSAGE);
		JOptionPane.showMessageDialog(null,"message");
		JOptionPane.showMessageDialog(null, "message", "title", JOptionPane.INFORMATION_MESSAGE);
	}
}