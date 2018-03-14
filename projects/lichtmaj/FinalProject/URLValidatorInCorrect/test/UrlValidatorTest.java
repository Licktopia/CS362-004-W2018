

//import com.oracle.tools.packager.Log;
import junit.framework.TestCase;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!


//Jonathan Test add
//Jeff Test add


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   
   public void testManualTest()
   {
	   //UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES)
	   UrlValidator urlValidator = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   assertTrue(urlValidator.isValid("http://www.oregonstate.edu"));
	   assertTrue(urlValidator.isValid("http://www.oregonstate.com"));
	   assertTrue(urlValidator.isValid("www.oregonstate.edu"));
	   assertTrue(urlValidator.isValid("http://oregonstate.edu"));
	   assertTrue(urlValidator.isValid("oregonstate.edu"));
	   assertTrue(urlValidator.isValid("http://www"));
	   assertTrue(urlValidator.isValid("http://www.google.com"));
	   
   }   
   
  //partition based on valid url schemes-----------------------------------------------------------------------------------------------
   public void testValidSchemesPartition()
   {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int validUrlCounter = 0;
      //List<String> validUrls = Arrays.asList("http://www.oregonstate.edu", "http://www.google.com");
      List<String> validUrls = Arrays.asList("ftp://go.com:80", "http://go.com:80", "https://go.com:80", "h323://go.com:80", "go.com:80");
      for(String url : validUrls) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Valid URL, scheme is good");
            validUrlCounter++;
         }
         else {
            System.out.println(url + " invalid URL, scheme is no good");
         }
      }
      assertEquals(validUrls.size(), validUrlCounter);
   }
   
  //invalid scheme partition testing--------------------------------------------------------------------------------------------- 
   public void testInvalidSchemesPartition()
   {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int inValidUrlCounter = 0;
      List<String> inValidUrls = Arrays.asList("Ftp://go.com:80", "http:/go.com:80", "3ttps://go.com:80", "_323://go.com:80");
      for(String url : inValidUrls) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Valid URL, expected scheme to be bad");
            inValidUrlCounter++;
         }
         else {
            System.out.println(url + " Valid URL, scheme bad as expected");
         }
      }
      assertEquals(inValidUrls.size(), inValidUrlCounter);
   }
  //---------------------------------------------------------------------------------------------------------------
  //partitioning based on valid url authorities
   public void testValidAuthorityPartition(){
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int validUrlCounter = 0;
      List<String> validAuthority = Arrays.asList("ftp://go.com:80", "https://www.google.com", "https://go.com:80", "http://255.168.192.45", "go.com:80");
      for(String url : validAuthority) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Valid Url, authority is good");
            validUrlCounter++;
         }
         else {
            System.out.println(url + " invalid URL, authority is no good");
         }
      }
      assertEquals(validAuthority.size(), validUrlCounter);
   }
   
  //invalid authority partition testing--------------------------------------------------------------------------------------------- 
   public void testInvalidAuthorityPartition()
   {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int validUrlCounter = 0;
      List<String> inValidAuthority = Arrays.asList("ftp://", "http://134", "https://go.a", "http://256.255.168.12");
      for(String url : inValidAuthority) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Invalid URL, expected authority to be no good");
            validUrlCounter++;
         }
         else {
            System.out.println(url + " Invalid Url, authority bad as expected");
         }
      }
      assertEquals(inValidAuthority.size(), validUrlCounter);
   }
  //---------------------------------------------------------------------------------------------------------------------- 
  //partitioned based on valid url path
   public void testValidPathPartition()
   {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int validUrlCounter = 0;
      List<String> validPath = Arrays.asList("ftp://go.com:80/$87", "http://go.com:80/realone", "https://go.com:80/good", "h323://go.com:80/"); 
      for(String url : validPath) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Valid Url, path is good");
            validUrlCounter++;
         }
         else {
            System.out.println(url + " Invalid URL, path is no good");
         }
      }
      assertEquals(validPath.size(), validUrlCounter);
   }
  //invalid path partition testing--------------------------------------------------------------------------------------------- 
   public void testInvalidPathPartition()
   {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int inValidUrlCounter = 0;
      List<String> inValidPath = Arrays.asList("ftp://go.com:80/#24", "http://go.com:80/..", "https://go.com:80/234");
      for(String url : inValidPath) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " valid URL, expected path to be invalid");
            inValidUrlCounter++;
         }
         else {
            System.out.println(url + " Invalid Url, path invalid as expected");
         }
      }
      assertEquals(inValidPath.size(), inValidUrlCounter);
   }
   //-------------------------------------------------------------------------------------------------------------------------
   //Partition test for https vs. http addresses
   public void testHttpVSnonePartition()
   {
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      int validUrlCounter = 0;
      List<String> validPath = Arrays.asList("www.google.com", "http://www.google.com", "www.oregonstate.edu", "http://www.oregonstate.edu"); 
      for(String url : validPath) {
         if(urlValidator.isValid(url) == true){
            System.out.println(url + " Valid Url");
            validUrlCounter++;
         }
         else {
            System.out.println(url + " Invalid URL");
         }
      }
      assertEquals(validPath.size(), validUrlCounter);
   }
   //--------------------------------------------------------------------------------------------------------------------------
   
   public void testIsValid() {
      boolean noFailures = true;
      int failedTests = 0;
      UrlValidator urlValidator = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      for(String scheme : testSchemes) {
         for(String authority : testAuthorities) {
            for(String port : testPorts) {
               for(String path : testPaths) {
                  for(String query : testQueries) {
                     String url = scheme + authority + port + path + query;
                     boolean isValidUrl;
                     boolean validatorResult = false;
                     isValidUrl = validSchemes.contains(scheme) && validAuthorities.contains(authority) && validPorts.contains(port)
                             && validPaths.contains(path) && validQueries.contains(query);
                     try {
                        validatorResult = urlValidator.isValid(url);
                     }
                     catch (Error e) {
//                        Log.debug("Url validator failure with exception: " + e);
                     }
                     if (isValidUrl != validatorResult) {
                        failedTests++;
                        noFailures = false;
                        if (isValidUrl) {
                           System.out.println(url + " is valid but tested as invalid");
                        }
                        else {
                           String invalidText = findInvalidPart(scheme, authority, port, path, query);
                           System.out.println(url + " is not valid but tested as valid." + invalidText);
                        }

                     }
                  }
               }
            }
         }
      }
      System.out.println("Number of failed tests: " + failedTests);
      assertEquals(true, noFailures);
   }

   String findInvalidPart(String scheme, String authority, String port, String path, String query) {
      ArrayList<String> myArray = new ArrayList<String>();
      String text = " Invalid Parts: (";
      if(!validSchemes.contains(scheme)) {
         text = text + "scheme: " + scheme + ", ";
      }
      if(!validAuthorities.contains(authority)) {
         text = text + "authority: " + authority + ", ";
      }
      if(!validPorts.contains(port)) {
         text = text + "port: " + port + ", ";
      }
      if(!validPaths.contains(path)) {
         text = text + "path: " + path + ", ";
      }
      if(!validQueries.contains(query)) {
         text = text + "query: " + query;
      }
      text = text + ")";
      return text;
   }

   private List<String> validSchemes = Arrays.asList("http://", "https://", "ftp://", "");
   private List<String> testSchemes = Arrays.asList("http://", "https://", "ftp://", "", "abc", "test://", "http:/");
   private List<String> validAuthorities = Arrays.asList("www.cool.com", "cool.com", "cool.edu", "www.cool.org");
   private List<String> testAuthorities = Arrays.asList("www.cool.com", "cool.com", "cool.edu", "www.cool.org", "cool", "", "cool.");
   private List<String> validPorts = Arrays.asList(":8080", ":0", "", ":35656");
   private List<String> testPorts = Arrays.asList("", ":8080", ":0", ":35656", ":-8080", ":abc", ":78010");
   private List<String> validPaths = Arrays.asList("/image", "", "/image/image", "/1test");
   private List<String> testPaths = Arrays.asList("/image", "", "/image/image", "/1test", "/#", "/&#", "/#&*");
   private List<String> validQueries = Arrays.asList("?test=true", "", "?test=true&test1=false", "?cool=5");
   private List<String> testQueries = Arrays.asList("?test=true", "", "?test=true&test1=false", "?cool=5", "#", "?test#5", "###");
}
