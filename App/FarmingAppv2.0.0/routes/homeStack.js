import { createStackNavigator } from 'react-navigation-stack';
import { createAppContainer } from 'react-navigation';
import Home from '../screens/home';
import ReviewDetails from '../screens/reviewDetails';
import About from '../screens/about';
import Calculator from '../screens/calculator';
import Product_List from '../screens/productlist';
import Contacts from '../screens/contact';
import LoginPage from '../screens/loginpage';
import Graph from '../screens/graphs';
import SignUp from '../screens/Signup';
import LoginMenu from '../screens/loginMenu';
import MyAccount from '../screens/MyAccount';
import MyOrders from '../screens/Orders';
import CustomerService from '../screens/CustomerService';
import FarmingUpdates from '../screens/FarmingUpdates';
import { Alert } from 'react-native';
import N_vals from '../screens/Graphs/N_val';
import P_vals from '../screens/Graphs/P_vals';
import K_vals from '../screens/Graphs/K_vals';
import Temperature from '../screens/Graphs/temp';
import Humidity from '../screens/Graphs/humd';
import TermsOfService from '../screens/TermsOfService';
import newPost from '../screens/newPost';


const screens = {
  Home: {
    screen: Home,
  },
  LoginPage: {
    screen: LoginPage,
  },
  About: {
    screen: About,
  },
  Calculator: {
    screen: Calculator,
  },
  Product_List: {
    screen: Product_List,
  },
  Contacts: {
    screen: Contacts,
  }
  ,
  Graphs: {
    screen: Graph,
  },
  SignUp: {
    screen: SignUp,
  },
  LoginMenu: {
    screen: LoginMenu,
  },
  MyAccount: {
    screen: MyAccount,
  },
  MyOrders: {
    screen: MyOrders,
  },
  CustomerService: {
    screen: CustomerService,
  },
  FarmingUpdates: {
    screen: FarmingUpdates,
  },
  N_vals: {
    screen: N_vals,
  },
  P_vals: {
    screen: P_vals,
  },
  K_vals: {
    screen: K_vals,
  },
  Temperature: {
    screen: Temperature,
  },
  Humidity: {
    screen: Humidity,
  },
  TermsOfService: {
    screen: TermsOfService,
  },
  newPost: {
    screen: newPost,
  },
  ReviewDetails: {
    screen: ReviewDetails,
  },

};

// home stack navigator screens
const HomeStack = createStackNavigator(screens);

export default createAppContainer(HomeStack);


