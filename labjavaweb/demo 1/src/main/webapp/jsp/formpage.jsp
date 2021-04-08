<%@taglib uri = "http://www.springframework.org/tags/form" prefix = "form"%>
<!DOCTYPE HTML>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
    <body>
        <form:form method = "POST" action = "/datapage">
            <label for="title">Title</label>
            <input id="title" class="button" type="text" name="title" required/>
            <label for="title">subTitle</label>
            <input id="subtitle" class="button" type="text" name="subtitle" required/>
            <input class="button" type="submit" value="Add lot">
        </form:form>
        <a href="/landingpage">LandingPage</a>
        <a href="/datapage">Datapage</a>
    </body>
</html>