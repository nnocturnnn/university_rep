<%@taglib uri = "http://www.springframework.org/tags/form" prefix = "form"%>
<!DOCTYPE HTML>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
    <body>
        <form:form method = "POST">
            <label for="name">Name</label>
            <input id="name" class="button" type="text" name="name" required/>
            <label for="subName">Surname</label>
            <input id="subName" class="button" type="text" name="subName" required/>
            <label for="age">Age</label>
            <input id="age" class="button" type="text" name="age" required/>
            <label for="father">Father</label>
            <input id="father" class="button" type="text" name="father" required/>
            <input class="button" type="submit" value="Add lot">
        </form:form>
        <a href="/landingpage">LandingPage</a>
        <a href="/datapage">Datapage</a>
    </body>
</html>