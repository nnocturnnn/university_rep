package by.hiber.db.javac;

import by.hiber.db.javac.services.impl.OrderProductServiceImpl;
import by.hiber.db.javac.services.impl.OrderServiceImpl;
import by.hiber.db.javac.services.impl.ProductServiceImpl;

import static by.hiber.db.javac.util.CommonUtil.createOrders;
import static by.hiber.db.javac.util.HibernateUtil.closeFactory;
import static by.hiber.db.javac.services.MainServices.*;

/**
 * Main class with entry point.
 */
public class Main {

    private static OrderServiceImpl orderService = new OrderServiceImpl();
    private static OrderProductServiceImpl orderProductService = new OrderProductServiceImpl();
    private static ProductServiceImpl productService = new ProductServiceImpl();

    public static void main(String[] args) {
        createOrders(10);
        getOrderInfo(orderService.getById(1L));
        getOrderNumberByQuantityBySum(4L,2L);
        getOrderByProduct(productService.getById(7L));
        getOrderOfTheDayNotContainProduct(productService.getById(5L));
        createNewOrderOfTheDay();
        deleteOrdersByProductQuantity(orderProductService.getById(19L).getQuantity());
        closeFactory();
    }

}
