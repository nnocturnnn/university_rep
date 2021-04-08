<%@page contentType = "text/html;charset = UTF-8" language = "java" %>
<%@page isELIgnored = "false" %>
<%@taglib uri = "http://www.springframework.org/tags/form" prefix = "form"%>
<!DOCTYPE html>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<body>
    <h2>Data</h2>
    <table>
        <tr><th>Name</th><th>Surname</th><th>Age</th><th>Father</th></tr> 
    <c:forEach items="${empList}" var="lots">
        <tr><td>${lots.name}</td><td>${lots.subName}</td><td>${lots.age}</td><td>${lots.father}</td></tr> 
            </c:forEach>
        </table>
<a href="/formpage">Formpage</a>
<a href="/landingpage">Landingpage</a>

</body>
</html>