import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class JavaSHAHash 
{
	public static String SHA(String str) 
	{
		String sha = null;
		if(str == null) 
			return null;
		try 
		{
			MessageDigest md = MessageDigest.getInstance("SHA-1");
			md.update(str.getBytes(), 0, str.length());
			sha = new BigInteger(1, md.digest()).toString(16);
		}
		catch (NoSuchAlgorithmException e) 
		{
			e.printStackTrace();
		}
		return sha;
	}
	public static void main(String[] args) 
	{
		System.out.println("\tSecure Hash Algorithm");
		System.out.println("For null:");
		System.out.println("Null           = " + SHA(""));
		System.out.println("\nFor simple text:");
		System.out.println("Welcome to NEC = " + SHA("Welcome to NEC"));
		System.out.println("\nFor simple numbers:");
		System.out.println("1234567890 	   = " + SHA("1234567890"));
	}
}