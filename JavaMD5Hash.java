import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class JavaMD5Hash 
{
	public static String MD5(String str) 
	{
		String md5 = null;
		if(str == null) 
			return null;
		try 
		{
			MessageDigest md = MessageDigest.getInstance("MD5");
			md.update(str.getBytes(), 0, str.length());
			md5 = new BigInteger(1, md.digest()).toString(16);
		}
		catch (NoSuchAlgorithmException e) 
		{
			e.printStackTrace();
		}
		return md5;
	}
	public static void main(String[] args) 
	{
		System.out.println("\tMessage Digest Algorithm 5");
		System.out.println("For null:");
		System.out.println("Null           = " + MD5(""));
		System.out.println("\nFor simple text:");
		System.out.println("Welcome to NEC = " + MD5("Welcome to NEC"));
		System.out.println("\nFor simple numbers:");
		System.out.println("1234567890     = " + MD5("1234567890"));
	}
}