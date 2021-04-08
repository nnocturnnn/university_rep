<%@page contentType = "text/html;charset = UTF-8" language = "java" %>
<%@page isELIgnored = "false" %>
<%@taglib uri = "http://www.springframework.org/tags/form" prefix = "form"%>
<!DOCTYPE html>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<body>
    <h2>Data from file</h2>
    <table>
        <tr><th>Name</th><th>Surname</th><th>Age</th><th>Father</th></tr> 
    <c:forEach items="${empList}" var="lots">
        <tr><td>${lots.name}</td><td>${lots.subName}</td><td>${lots.age}</td><td>${lots.father}</td></tr> 
            </c:forEach>
        </table>
        <h2>Data from DB</h2>
        <table>
        <tr><th>Name</th><th>Surname</th><th>Age</th><th>Father</th></tr> 
    <c:forEach items="${empListy}" var="lotsy">
        <tr><td>${lotsy.name}</td><td>${lotsy.subName}</td><td>${lotsy.age}</td><td>${lotsy.father}</td></tr> 
            </c:forEach>
        </table>
        <h2>Data from Memory</h2>
        <table>
        <tr><th>Name</th><th>Surname</th><th>Age</th><th>Father</th></tr> 
    <c:forEach items="${empListyM}" var="lotsyM">
        <tr><td>${lotsyM.name}</td><td>${lotsyM.subName}</td><td>${lotsyM.age}</td><td>${lotsyM.father}</td></tr> 
            </c:forEach>
        </table>
<a href="/formpage">Formpage</a>
<a href="/landingpage">Landingpage</a>

</body>
</html>